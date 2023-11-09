# challenge binary name
ARG OUT_FILE=f
# name of the challenge
ARG CHAL_NAME="Matryoshka"
# name of file containing ssh banner text
ARG WELCOME_FILE=welcome.txt
# offset amount for flag obfuscation
ARG ROTATE_OFFSET=8
# password to root
ARG ROOT_PASSWORD=northeasternctf


FROM debian:buster-slim as build

ARG OUT_FILE
ARG WELCOME_FILE
ARG CHAL_NAME
ARG ROTATE_OFFSET

WORKDIR /challenge

COPY . .

RUN apt-get update \
    && apt-get install -y gcc make zip tar bzip2 gzip lzma rzip lrzip ncompress lzop \
    && make "BIN=$BIN" "CHAL_NAME=$CHAL_NAME" "WELCOME_FILE=$WELCOME_FILE" "ROTATE_OFFSET=$ROTATE_OFFSET"


# use staged build to reduce docker image size

FROM debian:buster-slim as main

ARG OUT_FILE
ARG WELCOME_FILE
ARG ROOT_PASSWORD

WORKDIR /challenge

COPY --from=build /challenge/$OUT_FILE /root

RUN apt-get update \
    # install ssh server for participants to access
    && apt-get install -y ssh zip tar bzip2 gzip lzma rzip lrzip ncompress lzop file \
    && apt-get autoremove \
    && apt-get clean \
    # set root password, so participants can ssh in
    && bash -c "echo -e -n \"$ROOT_PASSWORD\n$ROOT_PASSWORD\n\" | passwd root" \
    && mkdir -p /run/sshd \
    # allow root login
    && bash -c "echo \"PermitRootLogin yes\" >> /etc/ssh/sshd_config"

COPY --from=build /challenge/$WELCOME_FILE /etc/motd

EXPOSE 22/TCP

# launch ssh server
CMD ["/bin/sh", "-c", "/usr/sbin/sshd -D -e \"$@\""]

# build: docker build -t matryoshka .
# run: docker run -itd --rm -p 22:22 matryoshka

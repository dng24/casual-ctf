# challenge binary name
ARG BIN=stat
# name of the challenge
ARG CHAL_NAME="Imposter"
# name of file containing ssh banner text
ARG WELCOME_FILE=welcome.txt
# password to root
ARG ROOT_PASSWORD=northeasternctf

FROM debian:bullseye-slim as build

ARG BIN
ARG CHAL_NAME
ARG WELCOME_FILE

WORKDIR /challenge

COPY . .

# compile code to put the flag in the binary
RUN apt-get update \
    && apt-get install -y make gcc \
    && make "BIN=$BIN" "CHAL_NAME=$CHAL_NAME" "WELCOME_FILE=$WELCOME_FILE"


# use staged build to reduce docker image size

FROM debian:bullseye-slim as main

ARG BIN
ARG ROOT_PASSWORD
ARG WELCOME_FILE

COPY --from=build /challenge/$BIN /usr/bin

RUN apt-get update \
    && apt-get install -y ssh debsums \
    && apt-get autoremove \
    && apt-get clean \
    # configure ssh
    && bash -c "echo -e -n \"$ROOT_PASSWORD\n$ROOT_PASSWORD\n\" | passwd root" \
    && mkdir -p /run/sshd \
    # allow root login
    && bash -c "echo \"PermitRootLogin yes\" >> /etc/ssh/sshd_config" \
    # time stomp binaries in /bin and /usr/bin so users can't search for recently modified binaries
    && touch /bin/* \
    && touch /usr/bin/* \
    && echo "alias ls='ls --color=auto'" >> /root/.bashrc

COPY --from=build /challenge/$WELCOME_FILE /etc/motd

EXPOSE 22/TCP

CMD ["/bin/sh", "-c", "/usr/sbin/sshd -D -e \"$@\""]

# build: docker build -t imposter .
# run: docker run -itd --rm -p 22:22 imposter

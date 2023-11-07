# challenge binary name
ARG BIN=patience
# name of the challenge
ARG CHAL_NAME="Patience"
# name of file containing ssh banner text
ARG WELCOME_FILE=welcome.txt
# offset amount for flag obfuscation
ARG ROTATE_OFFSET=5
# password to root
ARG ROOT_PASSWORD=northeasternctf


FROM alpine:latest as build

ARG BIN
ARG WELCOME_FILE
ARG CHAL_NAME
ARG ROTATE_OFFSET

WORKDIR /challenge

COPY . .

RUN apk update \
    && apk add build-base \
    && make "BIN=$BIN" "CHAL_NAME=$CHAL_NAME" "WELCOME_FILE=$WELCOME_FILE" "ROTATE_OFFSET=$ROTATE_OFFSET"


# use staged build to reduce docker image size

FROM alpine:latest as main

ARG BIN
ARG WELCOME_FILE
ARG ROOT_PASSWORD

WORKDIR /challenge

COPY --from=build /challenge/$BIN /root

RUN apk update \
    # install ssh server for participants to access
    && apk add --no-cache openssh gdb \
    # set root password, so participants can ssh in
    && sh -c "echo -e -n \"$ROOT_PASSWORD\n$ROOT_PASSWORD\n\" | passwd root" \
    # make host key
    && ssh-keygen -A \
    # allow root login
    && sh -c "echo \"PermitRootLogin yes\" >> /etc/ssh/sshd_config"

COPY --from=build /challenge/$WELCOME_FILE /etc/motd

EXPOSE 22/TCP

# launch ssh server
CMD ["/bin/sh", "-c", "/usr/sbin/sshd -D -e \"$@\""]

# build: docker build -t patience .
# run: docker run -itd --rm -p 22:22 patience

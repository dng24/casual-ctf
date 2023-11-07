# challenge binary name
ARG BIN=partialFlags
# name of the challenge
ARG CHAL_NAME="Partial Flags"
# name of file containing ssh banner text
ARG WELCOME_FILE=welcome.txt
# password to root
ARG ROOT_PASSWORD=northeasternctf


FROM alpine:latest as build

ARG BIN
ARG WELCOME_FILE
ARG CHAL_NAME

WORKDIR /challenge

COPY . .

RUN apk update \
    && apk add build-base \
    && make "BIN=$BIN" "CHAL_NAME=$CHAL_NAME" "WELCOME_FILE=$WELCOME_FILE"


# use staged build to reduce docker image size

FROM alpine:latest as main

ARG BIN
ARG WELCOME_FILE
ARG ROOT_PASSWORD

WORKDIR /challenge

COPY --from=build /challenge/$BIN /root

RUN apk update \
    # install ssh server for participants to access
    && apk add --no-cache openssh \
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

# build: docker build -t partial_flags .
# run: docker run -itd --rm -p 22:22 partial_flags

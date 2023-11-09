# Imposter

## Category

Forensics

## Level

Easy

## Description

There is an imposter binary in the Docker container that is pretending to be a legit binary.

Find this binary in the system.

## Hint

None

## Files to upload to CTFd

* None - this is a Docker challenge

## Solution

Running `debsums -c` will print out `/usr/bin/stat`, which is the imposter binary. Running the
binary will print the flag out.

The default flag is `casual{stat_binary_be_sus}`.

## Build

The flag can be changed by modifying the contents of flag.txt.

The binary can be built locally by running `make`:

A Docker container can also be created:

1. `docker build -t imposter .` - build the container
2. `docker run -itd --rm -p 9999:9999 imposter` - run the container
3. `ssh root@localhost` with the password set to the `ROOT_PASSWORD` argument in the Dockerfile

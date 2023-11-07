# Patience

## Category

Reverse engineering

## Level

Medium

## Description

The flag will print out when you run the binary...you just gotta wait a bit.................

## Hint

What is preventing the flag from printing? What if we just skip that part?

## Files to upload to CTFd

If this is used as a static challenge:

* patience

Otherwise, if this is used as a Docker challenge, no files need to be uploaded.

## Solution

The binary sleeps for one day before it rotates and decrypts the flag before printing to the
console. The binary can be placed in a debugger, and the sleep instruction can be skipped, or the
argument passed into sleep can be set to 0. This way, the flag will print immediately.

The default flag is `casual{fast_forwarding_time}`.

## Build

The flag can be changed by modifying the contents of flag.txt.

The binary can locally be built by running `make`.

A Docker container can also be created:

1. Binary name, challenge name, text of the SSH banner, and SSH root password can be changed in the
Dockerfile.
2. `docker build -t patience .` - build the container
3. `docker run -itd --rm -p 22:22 patience` - run the container
4. `ssh root@localhost` with the password set to the `ROOT_PASSWORD` argument in the Dockerfile

## Credits

The AES library (aes.c and aes.h) was taken from https://github.com/kokke/tiny-AES-c/tree/master,
and the Base64 library (base64.c and base64.h) was taken from https://github.com/joedf/base64.c.

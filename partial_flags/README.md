# Partial Flags

## Category

Reverse engineering

## Level

Easy

## Description

The flag appears to have been stored in different pieces in the partialFlags binary. Piece back
together the flag to capture it.

Use `root:northeasternctf` to SSH into the Docker container.

## Hint

No hint

## Files to upload to CTFd

If this is used as a static challenge:

* partialFlags

Otherwise, if this is used as a Docker challenge, no files need to be uploaded.

## Solution

Running `strings` on the binary will reveal different parts of the flag, and participants can
guess the order of the pieces. However, to be sure of the correct order of the pieces, one would
have to trace through the assembly or decompiled code.

The default flag is `casual{bm9pY2UhIQo=}`.

## Build

The flag can be changed by modifying the contents of flag.txt.

The binary can locally be built by running `make`.

A Docker container can also be created:

1. Binary name, challenge name, text of the SSH banner, and SSH root password can be changed in the
Dockerfile.
2. `docker build -t partial_flags .` - build the container
3. `docker run -itd --rm -p 22:22 partial_flags` - run the container
4. `ssh root@localhost` with the password set to the `ROOT_PASSWORD` argument in the Dockerfile

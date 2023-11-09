# Where's My Data?

## Category

Reverse engineering

## Level

Medium

## Description

Something is hidden in this binary. You won't find it by running the binary.

## Hint

Can't find the flag? Maybe checking out the data section will help.

## Files to upload to CTFd

If this is used as a static challenge:

* data

Otherwise, if this is used as a Docker challenge, no files need to be uploaded.

## Solution

The flag is in a QR code hidden in the data section of the binary. A tool like Ghidra will show the QR code if you scroll to the data section.

The default flag is `casual{be_glad_this_qr_code_didnt_download_malware}`.

## Build

The flag can be changed by modifying the contents of flag.txt.

The binary can locally be built by running `make`.

A Docker container can also be created:

1. Binary name, challenge name, text of the SSH banner, and SSH root password can be changed in the
Dockerfile.
2. `docker build -t data .` - build the container
3. `docker run -itd --rm -p 22:22 data` - run the container
4. `ssh root@localhost` with the password set to the `ROOT_PASSWORD` argument in the Dockerfile

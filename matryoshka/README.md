# Matryoshka

## Category

Forensics

## Level

Easy

## Description

Russian dolls do a lot of nesting, and so does the file in this challnge.

## Hint

You may have to rename each file to have the correct extension.

## Files to upload to CTF

If this is used as a static challenge:

* f

Otherwise, if this is used as a Docker challenge, no files need to be uploaded.

## Solution

The flag is compressed and archived over and over again in 12 formats. Participants will have to
undo the compression and archives to get to the flag. The `file` command is useful in determining
the next compression tool to use. To uncompress, the order of the tools should be:

1. `zip`
2. `lzop`
3. `compress`
4. `rzip`
5. `tar`
6. `lzma`
7. `gzip`
8. `bzip2`
9. `gzip`
10. `tar`
11. This is an Excel file, which can be unzip just like any other file using `zip`

For the 12th step, there are two different files. One is located in `xl/worksheets/flag.xml`, and
the other file is located at `xl/worksheets/_ls/ls.xml.rels`. Both are `zip` files. When
`ls.xml.rels` is unzipped, a script named `ls` will appear. The password to unzip the
`xl/worksheets/flag.xml` file is located in a comment in the `ls` script. When
`xl/worksheets/flag.xml` is unzipped, a binary named .flag.txt.swp is created, which can be run on
the command line and will print out the flag.

The default flag is `casual{asual{sual{ual{al{l{flag}}}}}}`.

## Build

The flag can be changed by modifying the contents of flag.txt.

The binary can locally be built by running `make`.

A Docker container can also be created:

1. Binary name, challenge name, text of the SSH banner, and SSH root password can be changed in the
Dockerfile.
2. `docker build -t matryoshka .` - build the container
3. `docker run -itd --rm -p 22:22 matryoshka` - run the container
4. `ssh root@localhost` with the password set to the `ROOT_PASSWORD` argument in the Dockerfile

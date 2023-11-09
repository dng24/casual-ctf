FLAG := $(shell cat flag.txt)
BIN := stat
CHAL_NAME := Imposter
WELCOME_FILE := welcome.txt

CC = gcc

CFLAGS := -s

SRCS := stat.c

OBF_BIN := obf_flag

all: program welcome

# obfuscate the flag that is stored in the binary in the Docker container so that users can't
# simply search for the flag in the strings of each binary
obfuscator:
	$(CC) $(CFLAGS) -o $(OBF_BIN) obfuscateFlag.c

# run the obfuscation program and put it in the binary that will be placed in the Docker
# container
program: obfuscator
	$(CC) $(CFLAGS) '-DSHIFTED_FLAG="$(shell ./$(OBF_BIN) $(FLAG))"' -o $(BIN) $(SRCS)

# for ssh welcome banner in Docker container
welcome:
	./generateSSHWelcomeMessage.sh "$(WELCOME_FILE)" "$(CHAL_NAME)"

clean:
	rm -rf "$(BIN)" "$(OBF_BIN)" "$(WELCOME_FILE)"

.PHONY: clean

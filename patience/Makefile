FLAG := "$(shell cat flag.txt)"
BIN := patience
CHAL_NAME := Patience
WELCOME_FILE := welcome.txt
ROTATE_OFFSET := 5

CC = gcc

CFLAGS := -s -static

SRCS := patience.c

DEPENDENCIES := aes.c base64.c

ENCRYPT_BIN := encryptFlag

all: program welcome

encrypt:
	$(CC) $(CFLAGS) -o $(ENCRYPT_BIN) $(DEPENDENCIES) encryptFlag.c

# Flag is stored encrypted and roatated in binary
# the encryptFlag binary will encrypt and rotate the plaintext flag and the ciphertext will be
# placed in the final binary
program: encrypt
	$(eval VARS='-DROTATED_AND_ENCRYPTED_FLAG="$(shell ./$(ENCRYPT_BIN) $(FLAG))"' '-DOFFSET=$(ROTATE_OFFSET)')
	$(CC) $(CFLAGS) $(VARS) -o $(BIN) $(DEPENDENCIES) $(SRCS)

# for ssh welcome banner in Docker container
welcome:
	./generateSSHWelcomeMessage.sh "$(WELCOME_FILE)" "$(CHAL_NAME)" "$(BIN)"

clean:
	rm -rf "$(BIN)" "$(ENCRYPT_BIN)" "$(WELCOME_FILE)"

.PHONY: clean

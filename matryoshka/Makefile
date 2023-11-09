FLAG := "$(shell cat flag.txt)"
OUT_FILE := f
CHAL_NAME := Matryoshka
WELCOME_FILE := welcome.txt
ROTATE_OFFSET := 8

CC = gcc

CFLAGS := -s -static

SRCS := flag.c

DEPENDENCIES := base64.c

ENCODE_BIN := encodeFlag
PROGRAM_BIN := flag

all: compress welcome

encode:
	$(CC) $(CFLAGS) -o $(ENCODE_BIN) $(DEPENDENCIES) encodeFlag.c

# flag stored in encoded form in binary, will be printed when run
program: encode
	$(eval VARS='-DROTATED_FLAG="$(shell ./$(ENCODE_BIN) $(FLAG))"' '-DOFFSET=$(ROTATE_OFFSET)')
	$(CC) $(CFLAGS) $(VARS) -o $(PROGRAM_BIN) $(DEPENDENCIES) $(SRCS)

# compress the flag in many different types of layers
compress: program
	./compress.sh "$(OUT_FILE)"

# for ssh welcome banner in Docker container
welcome:
	./generateSSHWelcomeMessage.sh "$(WELCOME_FILE)" "$(CHAL_NAME)" "$(OUT_FILE)"

clean:
	rm -rf "$(OUT_FILE)" "$(ENCODE_BIN)" "$(PROGRAM_BIN)" "$(WELCOME_FILE)"

.PHONY: clean


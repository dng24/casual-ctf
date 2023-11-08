FLAG := "$(shell cat flag.txt)"
BIN := data
CHAL_NAME:= Where\'s My Data?
WELCOME_FILE := welcome.txt

CC = gcc

CFLAGS := -s -static

SRCS := data.c

all: program welcome

program:
	pip3 install -r requirements.txt
	python3 generateQRCode.py "$(FLAG)" qr.png
	ld -r -b binary -o qr.o qr.png
	$(CC) $(CFLAGS) -c -o data.o $(SRCS)
	$(CC) $(CFLAGS) -o $(BIN) qr.o data.o

# for ssh welcome banner in Docker container
welcome:
	./generateSSHWelcomeMessage.sh "$(WELCOME_FILE)" "$(CHAL_NAME)" "$(BIN)"

clean:
	rm -rf qr.png qr.o data.o "$(BIN)" "$(WELCOME_FILE)"

.PHONY: clean

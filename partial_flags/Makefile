FLAG := "$(shell cat flag.txt)"
BIN := partialFlags
CHAL_NAME := Partial Flags
WELCOME_FILE := welcome.txt

CC = gcc

CFLAGS := -s -static

SRCS := partialFlags.c

FLAG_SPLIT_BIN := getFlagPortion

all: program welcome

split_flag:
	$(CC) $(CFLAGS) -o $(FLAG_SPLIT_BIN) getFlagPortion.c

# Flag is stored in chunks in final binary, so that participants have to piece them back together
# break up the flag here and place each part of the flag into a different variable
program: split_flag
	$(eval FLAG0=$(shell ./$(FLAG_SPLIT_BIN) $(FLAG) 0))
	$(eval FLAG1=$(shell ./$(FLAG_SPLIT_BIN) $(FLAG) 1))
	$(eval FLAG2=$(shell ./$(FLAG_SPLIT_BIN) $(FLAG) 2))
	$(eval FLAG3=$(shell ./$(FLAG_SPLIT_BIN) $(FLAG) 3))

	$(eval VARS='-DFLAG_PART0="$(FLAG0)"' '-DFLAG_PART1="$(FLAG1)"' '-DFLAG_PART2="$(FLAG2)"' '-DFLAG_PART3="$(FLAG3)"')
	$(CC) $(CFLAGS) $(VARS) -o $(BIN) $(SRCS)

# for ssh welcome banner in Docker container
welcome:
	./generateSSHWelcomeMessage.sh "$(WELCOME_FILE)" "$(CHAL_NAME)" "$(BIN)"

clean:
	rm -rf "$(BIN)" "$(FLAG_SPLIT_BIN)" "$(WELCOME_FILE)"

.PHONY: clean

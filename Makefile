c=gcc
op=-Wall -Wextra
exe=hardcode.exe

all: hardcode.c
	$(c) $(op) hardcode.c -o $(exe)

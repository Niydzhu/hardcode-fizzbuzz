c=gcc
op=-Wall -Wextra
execFileName=run.exe

all: hardcodedFizzBuzz.c
	$(c) $(op) hardcodedFizzBuzz.c -o $(execFileName)

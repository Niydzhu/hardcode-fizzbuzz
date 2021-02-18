# Usage

1. Generating the hardcoded C file (Example with 10 lines of FizzBuzz)

```bash
make
```
```bash
./hardcode.exe 10
```

2. Executing the file

```bash
cd dest/ && make
```
```bash
./fizzbuzz.exe
```



# Output

> Files
```
📂hardcode-fizzbuzz
 ┣ 📂dest
 ┃ ┣ 📜fizzbuzz.c
 ┃ ┣ 📜fizzbuzz.exe
 ┃ ┗ 📜Makefile
 ┣ 📜hardcode.c
 ┣ 📜hardcode.exe
 ┣ 📜Makefile
 ┗ 📜README.md
```

> fizzbuzz.c
```c
/**
 * @file fizzbuzz.c
 * @author Robot
 * @brief The most efficient FizzBuzz out there!
 *
 */

#include <stdio.h>

int main(void)
{
	printf("1\n");
	printf("2\n");
	printf("Fizz\n");
	printf("4\n");
	printf("Buzz\n");
	printf("Fizz\n");
	printf("7\n");
	printf("8\n");
	printf("Fizz\n");
	printf("Buzz\n");

	return 0;
}
```

> Makefile
```Makefile
c=gcc
op=-Wall -Wextra
exe=fizzbuzz.exe

all: fizzbuzz.c
	$(c) $(op) fizzbuzz.c -o $(exe)
```



# About FizzBuzz

> FizzBuzz has been used as an interview screening device for Computer
> programmers. Writing computer program to output the first 100 FizzBuzz
> numbers is a trivial problem for any would-be computer programmer, so
> interviewers can easily filter out those with insufficient programming
> ability. ([Source](https://en.wikipedia.org/wiki/Fizz_buzz))

#### The program outputs :

* **Fizz** if the number is divisible by 3.
* **Buzz** if the number is divisible by 5.
* **FizzBuzz** if the number is divisible by 3 and by 5. 
* **The number itself** if the number is neither divisible by 3 nor by 5.

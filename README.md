# Usage

#### ( In the linux terminal )

1. Generating the hardcoded C file (Example with 25 lines of FizzBuzz) :

```bash
make
```
```bash
./run.exe 25
```

2. Now in the "destination" folder, executing the file :

```bash
make
```
```bash
./fizzbuzz.exe
```

3. Profit (You are now a programmer!)

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
	printf("11\n");
	printf("Fizz\n");
	printf("13\n");
	printf("14\n");
	printf("FizzBuzz\n");
	printf("16\n");
	printf("17\n");
	printf("Fizz\n");
	printf("19\n");
	printf("Buzz\n");
	printf("Fizz\n");
	printf("22\n");
	printf("23\n");
	printf("Fizz\n");
	printf("Buzz\n");

	return 0;
}
```


# FizzBuzz

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

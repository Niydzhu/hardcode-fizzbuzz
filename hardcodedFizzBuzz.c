/**
 * @file hardcodedFizzBuzz.c
 * @author Niiju
 * @brief Outputs a "fizzbuzz.c" file which is a hardcoded FizzBuzz, length
 * defined by the number in the argument of this file's executable.
 * It also creates a Makefile to quickly compile and then execute the fizzbuzz.
 * @version 1.0
 * @date 2020-11-24
 *
 */



/* ------------------------------------------------------------------------ */
/*                               Libraries                                  */
/* ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



/* ------------------------------------------------------------------------ */
/*                         Constants & Definitions                          */
/* ------------------------------------------------------------------------ */

#define DIRECTORY_NAME "destination"
#define EXECUTABLE_NAME "fizzbuzz.exe"



/* ------------------------------------------------------------------------ */
/*                               Prototypes                                 */
/* ------------------------------------------------------------------------ */

bool createCFile(char* dirName, int nbLines);
bool createMakefile(char* dirName);
char* fizzBuzz(int number);



/* ------------------------------------------------------------------------ */
/*                               Functions                                  */
/* ------------------------------------------------------------------------ */

/**
 * @brief Main function.
 *
 * @param argc Number of arguments
 * @param argv Arguments (argv[1] is the number of lines for the FizzBuzz)
 * @return (int) -1 or 1 if an error has occured, 0 otherwise.
 */
int main(int argc, char const* argv[])
{
    int nbLines;

    /* Exit conditions : Finding errors when executing */
    if (argc <= 1) {
        printf("ERROR: You must give a number of FizzBuzz lines to print !\n");
        exit(EXIT_FAILURE);
    }

    nbLines = atoi(argv[1]); // Retrieving the number of lines to print

    if (nbLines < 0) {
        printf("ERROR: You must give a number between 0 and 2147483647 !\n");
        exit(EXIT_FAILURE);
    }


    /* Processing the generation of directory and files */
    printf("You have chosen to print %d lines of FizzBuzz. \n\n", nbLines);

    // Creating the files, then checking if there was any errors during the creation
    if (!createCFile(DIRECTORY_NAME, nbLines) || !createMakefile(DIRECTORY_NAME)) {
        // If an error has occured during the creation of the files
        printf("\nERROR: An error has occured during the creation of the files !\nSee above to know what are the errors. \n");
        exit(EXIT_FAILURE);
    }

    printf("\nYou can now execute the Makefile in the \"%s\" directory using commands \"make\", then \"./%s\". \n", DIRECTORY_NAME, EXECUTABLE_NAME);

    exit(EXIT_SUCCESS);
}



/**
 * @brief Creates the "fizzbuzz.c" file.
 *
 * @param dirName Name of the directory to put the file in
 * @param nbLines Number of lines to print
 */
bool createCFile(char* dirName, int nbLines)
{
    printf("Creating \"fizzbuzz.c\" file... ");

    // File path
    char* fileName = (char*)malloc((strlen(dirName) + 1 + strlen("/fizzbuzz.c") + 1) * sizeof(char));
    strcat(fileName, dirName);
    strcat(fileName, "/fizzbuzz.c");

    FILE* f = fopen(fileName, "w");
    if (f == NULL) { // If the file can't get accessed
        printf("ERROR: File couldn't be accessed.\n ");
        return false;
    }

    // Top of the file
    fprintf(f, "/**\n * @file fizzbuzz.c\n * @author Robot\n * @brief The most efficient FizzBuzz out there!\n *\n */\n\n#include <stdio.h>\n\nint main(void)\n{\n");

    // Printfs of the Fizz and Buzzes!
    for (int i = 1; i <= nbLines; i++)
        fprintf(f, "\tprintf(\"%s\\n\");\n", fizzBuzz(i));

    // Bottom of the file
    fprintf(f, "\n\treturn 0;\n}\n");

    fclose(f);
    printf("Done. \n");
    return true;
}



/**
 * @brief Creates the Makefile.
 *
 * @param dirName Name of the directory to put the Makefile in
 */
bool createMakefile(char* dirName)
{
    printf("Creating \"Makefile\" file... ");

    // File path
    char* fileName = (char*)malloc((strlen(dirName) + 1 + strlen("/Makefile") + 1) * sizeof(char));
    strcat(fileName, dirName);
    strcat(fileName, "/Makefile");

    FILE* f = fopen(fileName, "w");
    if (f == NULL) { // If the file can't get accessed
        printf("ERROR: File couldn't be accessed.\n ");
        return false;
    }

    // Content of the Makefile
    fprintf(f, "c=gcc\n");
    fprintf(f, "op=-Wall -Wextra\n");
    fprintf(f, "execFileName=%s\n", EXECUTABLE_NAME);
    fprintf(f, "\nall: fizzbuzz.c\n");
    fprintf(f, "\t$(c) $(op) fizzbuzz.c -o $(execFileName)\n");

    fclose(f);
    printf("Done. \n");
    return true;
}



/**
 * @brief Returns "Fizz" if the number is divisible by 3, "Buzz" if the
 * number is divisible by 5, "FizzBuzz" if the number is divisible by 3 and by 5,
 * or the number if it's neither divisible by 3 nor by 5.
 *
 * @param number The number
 * @return (char*) "Fizz", "Buzz", "FizzBuzz" or the number.
 */
char* fizzBuzz(int number)
{
    char* result = (char*)malloc(9 * sizeof(char)); // 9 => Length of "FizzBuzz" + '\0'
    char* numberString = (char*)malloc(11 * sizeof(char)); // 11 => (Number of digits in max int (10) + '\0')

    sprintf(numberString, "%d", number);

    if (number % 3 == 0)
        strcat(result, "Fizz");

    if (number % 5 == 0)
        strcat(result, "Buzz");

    if (number % 3 != 0 && number % 5 != 0) {
        result = (char*)malloc(11 * sizeof(char)); // 11 => (Number of digits in max int (10) + '\0')
        strcpy(result, numberString);
    }

    return result;
}

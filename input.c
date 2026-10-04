#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

/*
 * Student 6 Contribution:
 * Shared input validation functions for the MFMS.
 * Provides reusable validation for integers, menu choices,
 * non-negative numbers and text input.
 */

/*
 * Clears all remaining characters from the input buffer.
 */

/*
 * Reads a valid integer.
 */
int getInt(const char *prompt)
{
    int value;
    char line[100];

    while (1)
    {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            continue;
        }

        char *end;
        value = (int)strtol(line, &end, 10);

        if (end != line)
        {
            while (*end == ' ' || *end == '\t')
                end++;

            if (*end == '\n' || *end == '\0')
                return value;
        }

        printf("Invalid input. Please enter a whole number.\n");
    }
}

/*
 * Reads a valid non-negative floating-point number.
 */
float getNonNegativeFloat(const char *prompt)
{
    float value;
    char line[100];

    while (1)
    {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            continue;
        }

        char *end;
        value = strtof(line, &end);

        if (end != line)
        {
            while (*end == ' ' || *end == '\t')
                end++;

            if ((*end == '\n' || *end == '\0') && value >= 0)
                return value;
        }

        printf("Invalid input. Please enter a non-negative number.\n");
    }
}

/*
 * Reads a menu choice within a specified range.
 */
int getMenuChoice(const char *prompt, int min, int max)
{
    int choice;

    while (1)
    {
        choice = getInt(prompt);

        if (choice >= min && choice <= max)
            return choice;

        printf("Invalid choice. Please enter a number from %d to %d.\n",
               min, max);
    }
}

/*
 * Safely reads a string.
 */
void getString(const char *prompt, char *buffer, int size)
{
    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, size, stdin) == NULL)
        {
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) > 0)
            return;

        printf("Input cannot be empty. Please try again.\n");
    }
}
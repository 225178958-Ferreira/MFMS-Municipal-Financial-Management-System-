#ifndef INPUT_H
#define INPUT_H

/*
 * Reads and validates an integer from the user.
 * Keeps asking until a valid integer is entered.
 */
int getInt(const char *prompt);

/*
 * Reads and validates a non-negative floating-point number.
 * Keeps asking until a valid number is entered.
 */
float getNonNegativeFloat(const char *prompt);

/*
 * Reads a menu choice between min and max.
 */
int getMenuChoice(const char *prompt, int min, int max);

/*
 * Reads a line of text safely from the user.
 */
void getString(const char *prompt, char *buffer, int size);

#endif
#include "base_change.h"

/* Custom atoi function that converts string to long long
 * Returns -1 if the input is invalid
 * Only accepts positive integers
 */
long long a2i(char *s) {
    /* Skip leading whitespace */
    while (isspace(*s)) {
        s++;
    }

    /* Check if first character is a digit */
    if (!isdigit(*s)) {
        return -1;
    }

    long long value = 0;

    /* Convert each digit */
    while (isdigit(*s)) {
        value = value * 10 + (*s - '0');
        s++;
    }

    /* Check if we've reached the end of string */
    if (*s == '\0') {
        return value;
    } else {
        return -1;  /* Invalid characters found */
    }
}
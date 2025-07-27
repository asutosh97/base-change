#include "base_change.h"

/* Convert a number from base 2-10 to decimal */
long long twotonine_to_decimal(long long number, long long base) {
    long long remainder, multiplier = 1, result = 0;

    while (number > 0) {
        remainder = number % 10;
        result += remainder * multiplier;
        multiplier *= base;
        number /= 10;
    }

    return result;
}

/* Convert a decimal number to base 2-10 */
long long decimal_to_twotonine(long long number, long long base) {
    long long result = 0, remainder, multiplier = 1;

    while (number > 0) {
        remainder = number % base;
        result += remainder * multiplier;
        multiplier *= 10;
        number /= base;
    }

    return result;
}

/* Convert a string from base 11-20 to decimal */
long long elevenup_to_decimal(char *s, long long base) {
    long long decimal_value = 0, multiplier = 1;
    int length = strlen(s);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            decimal_value += (s[i] - '0') * multiplier;
        } else {
            decimal_value += (s[i] - 'A' + 10) * multiplier;
        }
        multiplier *= base;
    }

    return decimal_value;
}

/* Convert a decimal number to base 11-20 string representation */
void decimal_to_elevenup(long long decimal_value, long long target_base, char *result) {
    int index = 0, remainder;

    if (decimal_value == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    while (decimal_value > 0) {
        remainder = decimal_value % target_base;
        if (remainder < 10) {
            result[index++] = remainder + '0';
        } else {
            result[index++] = remainder - 10 + 'A';
        }
        decimal_value /= target_base;
    }

    result[index] = '\0';
    strrev(result);
}

/* Reverse a string in place */
void strrev(char *s) {
    int length = strlen(s);
    char temp;

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* Check if a number (base 2-10) is valid for the given base */
int twotonine_check(long long number, long long base) {
    while (number > 0) {
        if (number % 10 >= base) {
            return 0;  /* Invalid digit for this base */
        }
        number /= 10;
    }
    return 1;  /* Valid */
}

/* Check if a string (base 11-20) is valid for the given base */
int elevenup_check(char *s, long long base) {
    while (*s != '\0') {
        if (isdigit(*s)) {
            if ((*s - '0') >= base) {
                return 0;  /* Invalid digit for this base */
            }
        } else if (isupper(*s)) {
            if ((*s - 'A' + 10) >= base) {
                return 0;  /* Invalid letter for this base */
            }
        } else {
            return 0;  /* Invalid character */
        }
        s++;
    }
    return 1;  /* Valid */
}
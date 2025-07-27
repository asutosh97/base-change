#include "base_change.h"

/* Helper function to clear input buffer */
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Helper function to wait for user to press enter */
void wait_for_enter(void) {
    printf("Press ENTER to try again...");
    clear_input_buffer();
}

/* Function to get and validate base input */
int get_base_input(const char *prompt) {
    long long base;

    while (1) {
        printf("%s", prompt);
        if (scanf("%lld", &base) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            wait_for_enter();
            continue;
        }
        clear_input_buffer();

        if (base < MIN_BASE || base > MAX_BASE) {
            printf("Base limit exceeded! Please enter a base between %d and %d.\n",
                   MIN_BASE, MAX_BASE);
            wait_for_enter();
            continue;
        }

        return (int)base;
    }
}

/* Function to get and validate value input */
int get_value_input(char *value, int base) {
    printf("Enter the value: ");
    if (scanf("%99[^\n]", value) != 1) {
        clear_input_buffer();
        return ERROR_INVALID_INPUT;
    }
    clear_input_buffer();

    if (base <= DECIMAL_BASE_THRESHOLD) {
        long long numeric_value = a2i(value);
        if (numeric_value == -1) {
            return ERROR_INVALID_INPUT;
        }
        if (!twotonine_check(numeric_value, base)) {
            return ERROR_INVALID_INPUT;
        }
    } else {
        if (!elevenup_check(value, base)) {
            return ERROR_INVALID_INPUT;
        }
    }

    return SUCCESS;
}

/* Function to convert input value to decimal */
long long convert_to_decimal(const char *value, int base) {
    if (base <= DECIMAL_BASE_THRESHOLD) {
        long long numeric_value = a2i((char *)value);
        return twotonine_to_decimal(numeric_value, base);
    } else {
        return elevenup_to_decimal((char *)value, base);
    }
}

/* Function to print the final result */
void print_result(long long decimal_value, int target_base) {
    if (target_base <= DECIMAL_BASE_THRESHOLD) {
        long long result = decimal_to_twotonine(decimal_value, target_base);
        printf("The answer is: %lld\n", result);
    } else {
        char result[MAX];
        decimal_to_elevenup(decimal_value, target_base, result);
        printf("The answer is: %s\n", result);
    }
}

/* Main program function */
int main(void) {
    int source_base, target_base;
    char value[MAX];
    long long decimal_value;

    printf("Welcome to the Base Change Program!\n");
    printf("=====================================\n\n");

    while (1) {
        /* Get source base */
        source_base = get_base_input("Enter the source base: ");

        /* Get and validate input value */
        while (get_value_input(value, source_base) != SUCCESS) {
            printf("Invalid input for base %d!\n", source_base);
            wait_for_enter();
        }

        /* Convert input to decimal */
        decimal_value = convert_to_decimal(value, source_base);

        /* Get target base */
        target_base = get_base_input("Enter the target base: ");

        /* Print result */
        print_result(decimal_value, target_base);

        /* Ask if user wants to continue */
        printf("\nDo you want to perform another conversion? (y/n): ");
        char choice;
        if (scanf(" %c", &choice) == 1 && (choice == 'y' || choice == 'Y')) {
            clear_input_buffer();
            printf("\n");
            continue;
        } else {
            break;
        }
    }

    printf("\nThank you for using the Base Change Program!\n");
    return SUCCESS;
}
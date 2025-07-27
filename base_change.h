#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Constants */
#define MAX 100
#define MIN_BASE 2
#define MAX_BASE 20
#define DECIMAL_BASE_THRESHOLD 10
#define SUCCESS 0
#define ERROR_INVALID_INPUT -1
#define ERROR_BASE_LIMIT -2

/* Function declarations */
long long twotonine_to_decimal(long long, long long);
long long decimal_to_twotonine(long long, long long);
long long elevenup_to_decimal(char *, long long);
void decimal_to_elevenup(long long, long long, char *);
int twotonine_check(long long, long long);
int elevenup_check(char *, long long);
long long a2i(char *);
void strrev(char *);

/* New helper functions */
int get_base_input(const char *prompt);
int get_value_input(char *value, int base);
long long convert_to_decimal(const char *value, int base);
void convert_from_decimal(long long decimal_value, int target_base, char *result);
void print_result(long long decimal_value, int target_base);
void clear_input_buffer(void);
void wait_for_enter(void);
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
long long twotonine_to_decimal(long long,long long);
long long decimal_to_twotonine(long long,long long);
long long elevenup_to_decimal(char *,long long);
void decimal_to_elevenup(long long,long long,char *);
int twotonine_check(long long,long long);
int elevenup_check(char *,long long);
long long a2i(char *);  			//input will be in string for all the bases  use this function only for base 2 to 10,return -1 if the input is invalid
void strrev(char *);
#define MAX 100
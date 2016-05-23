#include"base_change.h"
long long a2i(char *s)
{
	while(isspace(*s++));
	if(!isdigit(*s))
		return -1;
	long long value;
	for(value=0;isdigit(*s);s++)
		value=value*10+(*s-'0');
	if(*s=='\0')
		return value;
	else
		return -1;
}
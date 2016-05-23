#include"base_change.h"
long long twotonine_to_decimal(long long number,long long base)
{
	long long r,k=1,ans=0;
	while(number)
	{
		r=number%10;
		ans=ans+r*k;
		k=k*base;
		number=number/10;
	}
	return ans;
}
long long decimal_to_twotonine(long long number,long long base)
{
	long long ans=0,r,k=1;
	while(number)
	{
		r=number%base;
		ans=ans+r*k;
		k=k*10;
		number=number/base;
	}
	return ans;
}
long long elevenup_to_decimal(char *s,long long base)
{
	long long dec=0,k=1;
	int j;
	for(j=strlen(s)-1;j>=0;j--,k*=base)
	{
		switch(isdigit(s[j]))
		{
			case 1:
					dec=dec+(s[j]-'0')*k;
					break;
			case 0:
					dec=dec+(s[j]-'A'+10)*k;
					break;
		}
	}
	return dec;
}
void decimal_to_elevenup(long long dec,long long target,char *s)
{
	int i=0,r;
	while(dec)
	{
		r = dec % target ;
		s[i++] = (r<10) ? r + '0': ('A' - 10 + r );
		dec = (dec/target) ;
	}
	s[i]='\0';
	strrev(s);
}
void strrev(char *s)
{
	int i,j;
	char temp;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}

}
int twotonine_check(long long number,long long base)
{
	while(number)
	{
		if( number % 10 >= base )
			return 0;
		number /= 10;
	}
	return 1;
}

int elevenup_check(char *s,long long base)
{
	while(*s!='\0')
	{
		if(!isdigit(*s))
		{
			if(*s-'A'+10 >= base)
				return 0;
		}
	s++;
	}
	return 1;
}
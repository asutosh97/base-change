#include"base_change.h"
int main()
{
	X:
	system("clear");
	long long s,t,v,dec,ans;
	char value[MAX],answer[MAX];
	printf("Welcome to base change program.\n");
	printf("Enter the source base:");
	scanf("%lld",&s);
	getchar();
	if(s<2||s>20)
	{
		printf("Limit Exceeded!!!\n");
		exit(0);
	}
	if(s<=10)
	{
		printf("Enter the value:");
		scanf("%[^\n]",value);
		getchar();
		v=a2i(value);
		if(v==-1)
		{
			printf("Invalid Input!!!\n");
			printf("Press ENTER to try again....");
			while(getchar()!='\n');
			goto X;
		}
		if(!twotonine_check(v,s))
		{
			printf("Invalid Input!!!\n");
			printf("Press ENTER to try again....");
			while(getchar()!='\n');
			goto X;
		}
		dec=twotonine_to_decimal(v,s);
	}
	else
	{
		printf("Enter the value : ");
		scanf("%[^\n]",value);
		getchar();
		if(!elevenup_check(value,s))
		{
			printf("Invalid Input!!!\n");
			printf("Press ENTER to try again.....");
			while(getchar()!='\n');
			goto X;
		}
		dec=elevenup_to_decimal(value,s);
	}
	printf("Enter the target base:");
	scanf("%lld",&t);
	getchar();
	if(t<2||t>20)
	{
		printf("Limit Exceeded!!!\n");
		exit(0);
	}
	if(t<=10)
	{
		ans=decimal_to_twotonine(dec,t);
		printf("The answer is : %lld\n",ans);
	}
	else
	{
		decimal_to_elevenup(dec,t,answer);
		printf("The answer is : %s\n",answer);
	}
	return 0;
}
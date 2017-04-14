#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char *start, char *end)
{
	while (start<end)
	{
		if (*start != *end)
		{
			return false;
		}
		else
		{
			start++;
			end--;
		}
	}
	return true;
}

int main()
{
	char *str = (char *)malloc(sizeof(char) * 10);
	memset(str, '\0', 10);
	while (gets(str)!=NULL)
	{
		char *start = str;
		char *end = str + strlen(str) - 1;
		while ((start<end)&&(*start == *end))
		{
			start++;
			end--;
		}
		
		if (start >= end)
		{
			printf("YES\n");
		}
		else if (isPalindrome(start + 1, end))
		{
			printf("YES\n");
		}
		else if(isPalindrome(start, end - 1))
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}
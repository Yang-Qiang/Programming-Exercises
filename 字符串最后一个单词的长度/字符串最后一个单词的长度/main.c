#include<stdio.h>
#include<string.h>
#define MAX_SIZE	5000
int main()
{
	char a[MAX_SIZE]={ '\0' };
	int count = 0;
	while (NULL!=gets(a))
	{
		for (int i = strlen(a) - 1;i >= 0;i--) {
			if (' ' == a[i]) continue;
			while (i>=0&&a[i]!=' ')
			{
				count++;
				i--;
			}
			break;
		}
		printf("%d\n", count);
	}

}
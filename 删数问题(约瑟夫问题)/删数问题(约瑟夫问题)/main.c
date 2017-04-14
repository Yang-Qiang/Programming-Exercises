#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d", n);
	int *p = (int *)malloc(sizeof(int)*n);
	for (int i = 0;i < n;i++)
	{
		p[i] = i;
	}



}
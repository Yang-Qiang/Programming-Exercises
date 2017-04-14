#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define	MAX_SIZE	1000
int main()
{
	char str[MAX_SIZE][MAX_SIZE];
	int n = 0;
	while (gets(str[n]) != NULL) {
		++n;
	}
	int a = 0, b = 0, c = 0, d = 0;
	int i = 0;
	int j = 0;
	for (i = 0;i < n;i++) {
		a = 0;b = 0;c = 0;d = 0;
		for (j = 0;str[i][j] != '\0';j++) {
			if (isdigit(str[i][j]))			a = 1;
			else if (isupper(str[i][j]))	b = 1;
			else if (islower(str[i][j]))	c = 1;
			else d = 1;
		}
		if (a + b + c + d < 3 || j <= 8) printf("NG\n");
		else
		{
			int length = strlen(str[i]) - 3;
			char temp[4];
			char *p = NULL;
			for (j = 0;j < length;j++) {
				strncpy(temp, &str[i][j], 3);
				temp[3] = '\0';
				p = strstr(str[i], temp);
				if (p != NULL&&p != &str[i][j]) {
					printf("NG\n");
					break;
				}
			}
			if (j > length)
				printf("OK\n");
		}
	}
	return 0;
}
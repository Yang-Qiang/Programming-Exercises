#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void reverse(char *start, char*end)
{
	if (NULL == start || NULL == end)	return;
	char temp;
	for (;start < end;start++,end--) {
		temp = *start;
		*start = *end;
		*end = temp;
	}
}

int main()
{
	char str[1000] = { '\0' };
	while (gets(str)){
		int alphaCount = 0;	//������ĸ����
		int count = 0;		//�ǵ�����ĸ����ת��Ϊ�ո������Ҫ�Ŀո���
		int i = 0;
		int j = 0;
		int len = strlen(str);
		for (i = 0;i < len;i++) {
			if (isalpha(str[i])) {
				alphaCount++;
			}
			else {
				while (i < len&&isalpha(str[i]) == 0) i++;  
				count++;
				i--;
			}
		}
		char *p = (char *)malloc(sizeof(char)*(alphaCount + count+1));
		int k = 0;
		for (i = 0, k = 0;i < len&&k < alphaCount + count;i++) {
			if (isalpha(str[i])) {
				p[k++] = str[i];
			}
			else {
				while (i < len&&isalpha(str[i]) == 0) i++;
				p[k++] = ' ';
				i--;
			}
		}
		p[k] = '\0';
		char *start = p;
		char *end = p + alphaCount + count-1;
		if (' ' == *start)	start = start + 1;		//�ַ�����һ���ǿո�
		if (' ' == *end) end = end - 1;				//�ַ������һ���ǿո�
		reverse(start, end);
		char *p1 = p;
		char *p2 = NULL;
		for (;p1<=end;) {
			p2 = p1 + 1;
			while (p2<=end&&' '!=*p2) {
				p2++;
			}
			reverse(p1, p2 - 1);
			p1 = p2 + 1;
		}
		printf("%s\n", p);
		free(p);
		memset(str, '\0', 1000);
	}
}
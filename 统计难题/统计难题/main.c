#include <stdio.h>
#include <string.h>

struct tree {
	int num;
	struct tree* next[26];
};
typedef struct tree dtree;
dtree t[1000000];
char s[20];

int main()
{
	int l, i, ind, j, f;
	dtree root, *tmp;
	ind = 0;

	root.num = 0;
	for (i = 0;i<26;i++)
		root.next[i] = NULL;;


	while (1)
	{
		gets(s);

		l = strlen(s);

		if (l == 0)
			break;
		tmp = &root;

		for (i = 0;i<l;i++)
		{
			if (tmp->next[s[i] - 'a'] == NULL)
			{
				tmp->next[s[i] - 'a'] = &t[ind];
				t[ind].num = 0;
				for (j = 0;j<26;j++)
				{
					t[ind].next[s[i] - 'a'] = NULL;
				}

				ind++;
			}

			tmp = tmp->next[s[i] - 'a'];

			tmp->num++;
		}

	}

	while (scanf("%s", s) != EOF)
	{
		l = strlen(s);
		tmp = &root;
		f = 0;
		for (i = 0;i<l;i++)
		{
			if (tmp->next[s[i] - 'a'] != NULL)
			{
				tmp = tmp->next[s[i] - 'a'];
			}
			else
			{
				f = 1;
				break;
			}
		}

		if (f == 0)
			printf("%d\n", tmp->num);
		else
			printf("%d\n", 0);
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 220010
int N, p[MAXD];
char str[MAXD], b[MAXD];
void init()
{
	int i;
	for (i = 0; str[i]; i++) b[2 * i + 1] = '#', b[2 * i + 2] = str[i];
	N = 2 * i + 1;
	b[0] = '$', b[N] = b[N + 1] = '#';
}
void solve()
{
	int i, id, max = 0, ans = 0;
	for (i = 1; i <= N; i++)
	{
		p[i] = i < max ? std::min(max - i, p[2 * id - i]) : 1;
		while (b[i + p[i]] == b[i - p[i]]) ++p[i];
		if (i + p[i] > max) max = i + p[i], id = i;
		ans = std::max(ans, p[i] - 1);
	}
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%s", str) == 1)
	{
		init();
		solve();
	}
	return 0;
}
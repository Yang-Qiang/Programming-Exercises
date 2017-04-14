#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAXD 220010
int N=0;
int p[MAXD] = { 0 };
char str[MAXD], b[MAXD];
void Init()
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		b[2 * i + 1] = '#', b[2 * i + 2] = str[i];
	}
	N = 2 * i + 1;
	b[0] = '$';
	b[N] = b[N + 1] = '#';
}
void Manacher()
{
	int i = 0;
	int id = 0;
	int max = 0;
	int ans = 0;
	for (i = 1; i <= N; i++)
	{
		p[i] = i < max ? min(max - i, p[2 * id - i]) : 1;
		while (b[i + p[i]] == b[i - p[i]]) ++p[i];
		if (i + p[i] > max) max = i + p[i], id = i;
		ans = std::max(ans, p[i] - 1);	
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> str)
	{
		Init();
		Manacher();
	}
	return 0;
}

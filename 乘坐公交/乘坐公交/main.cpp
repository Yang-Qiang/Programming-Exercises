#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//因为至少调到一条鱼的情况比较多，所以考虑对立事件，一个鱼也钓不到的情况
//又因为每分钟钓到鱼和钓不到鱼都是独立事件，互不影响，（感觉又回到高中了 = =）
//把每分钟钓不到鱼的概率相乘，也就是求它的t次方，就是t分钟钓不到鱼的概率了。
//最后用1减去这个概率就是能钓到鱼的概率了。
void GetWiner(int n,int m,int x,int y,int t,float **p)
{
	float pss = 0.0;
	float pcc = 0.0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			pss += p[i][j];
		}
	}
	pss = pss / m / n;
	pss = 1 - pow(1 - pss, t);

	pcc = 1 - pow((1 - p[x][y]), t);
	cout.setf(ios::fixed);
	if (pss == pcc)
	{
		cout << "equal" << endl;
		cout << setprecision(2)<<pss << endl;
	}
	if (pss<pcc)
	{
		cout << "cc" << endl;
		cout << setprecision(2)<< pcc << endl;
	}
	if (pss>pcc)
	{
		cout << "ss" << endl;
		cout << setprecision(2)<< pss << endl;
	}
		
}

int main()
{
	int n, m, x, y, t;
	while (cin >> n >> m >> x >> y >> t)
	{
		float **p = new float *[(n + 1)];
		for (int i = 0;i <= n;i++)
		{
			p[i] = new float[m + 1];
		}
		for (int i = 0;i <= n;i++)
		{
			for (int j = 0;j <= m;j++)
			{
				p[i][j] = 0.0;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				cin >> p[i][j];
			}
		}

		GetWiner(n,m,x,y,t,p);

		for (int i = 0;i <= n;i++)
		{
			delete []p[i];
		}

		delete p;

	}
	return 0;
}
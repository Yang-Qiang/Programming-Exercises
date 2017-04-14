#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//��Ϊ���ٵ���һ���������Ƚ϶࣬���Կ��Ƕ����¼���һ����Ҳ�����������
//����Ϊÿ���ӵ�����͵������㶼�Ƕ����¼�������Ӱ�죬���о��ֻص������� = =��
//��ÿ���ӵ�������ĸ�����ˣ�Ҳ����������t�η�������t���ӵ�������ĸ����ˡ�
//�����1��ȥ������ʾ����ܵ�����ĸ����ˡ�
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
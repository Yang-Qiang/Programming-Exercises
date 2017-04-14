#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define	MAX_SIZE	10000

void minDistance(string strA, string strB,int **dist)
{
	if (" "==strA || " "== strB||NULL==dist) {
		return ;
	}
	int lenA = strA.size();
	int lenB = strB.size();
	int temp = 0;
	int d = 0;
	for (int i = 1;i <= lenA;i++) {
		for (int j = 1;j <= lenB;j++) {
			if (strA[i - 1] == strB[j - 1])	d = 0;
			else d = 1;
			temp = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1);
			dist[i][j] = min(temp, dist[i - 1][j - 1] + d);
		}
	}
}
int main()
{
	string strA;
	string strB;
	while (cin>>strA>>strB)
	{
		int lenA = strA.size();
		int lenB = strB.size();
		int **dist = new int *[lenA+1];
		for (int i = 0;i <= lenA;i++) {
			dist[i] = new int[lenB+1];
		}
		for (int i = 0;i <=lenA;i++) {
			for (int j = 0;j<=lenB;j++) {
				dist[i][j] = 0;
			}
		}
		for (int i = 0;i <=lenA;i++) {
			dist[i][0] = i;
		}
		for (int i = 0;i <= lenB;i++) {
			dist[0][i] = i;
		}
		minDistance(strA, strB,dist);
		cout << dist[lenA][lenB] << endl;
		for (int i = 0;i < lenA;i++) {
			delete []dist[i];
			dist[i] = NULL;
		}
		delete []dist;
		dist = NULL;
	}
}
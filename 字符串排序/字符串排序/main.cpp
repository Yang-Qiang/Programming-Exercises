#include<vector>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	vector<char> tempChar;
	while (getline(cin, s)) {
		int length = s.size();
		tempChar.clear();
		for (int i = 0;i < 26;i++) {
			for (int j = 0;j < length;j++) {
				if (isalpha(s[j])) {				//ÊÇ×ÖÄ¸
					if (s[j] - 'a' == i || s[j] - 'A' == i)
						tempChar.push_back(s[j]);
				}
			}
		}
		int size = tempChar.size();
		for (int i = 0, k = 0;i < length&&k<size;i++) {
			if (isalpha(s[i])) {
				s[i] = tempChar[k++];
			}
		}
		cout << s << endl;
	}
	return 0;
}
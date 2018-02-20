#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("hightemp.txt", "r", stdin);
	freopen("output.csv", "w", stdout);

	int cnt = 0;
	string inp[4];

	char comma = ','; char newline = '\n';
	while(cin >> inp[0] >> inp[1] >> inp[2] >> inp[3]){
		if(cnt % 50 == 0){
			cout << inp[0] << comma;
			cout << inp[1] << comma;
			cout << inp[2] << comma;
			cout << inp[3] << newline;
		}
		cnt++;
	}
}
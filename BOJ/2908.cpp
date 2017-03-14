#include <bits/stdc++.h>

using namespace std;

int main()
{
	string inp1,inp2;
	cin>>inp1>>inp2;

	reverse(inp1.begin(),inp1.end());
	reverse(inp2.begin(),inp2.end());

	int a,b;
	a=atoi(inp1.c_str());
	b=atoi(inp2.c_str());
	printf("%d\n",max(a,b));
}
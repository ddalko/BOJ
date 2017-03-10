#include <bits/stdc++.h>

using namespace std;

int dp[101][10002];
vector<pair<int,int>> c;

int main()
{
	int t,k;
	scanf("%d %d",&t,&k);

	for(int i=0;i<k;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		c.push_back(make_pair(a,b));
	}
	sort(c.begin(),c.end());

	dp[0][0]=1;
	for(int i=1;i<=k;++i){
		for(int count=0;count<=c[i-1].second;++count){
			for(int j=0;j<=t;++j){
				if(j+c[i-1].first*count>t) break;
				else dp[i][j+c[i-1].first*count]+=dp[i-1][j];
			}
		}
	}
	printf("%d\n",dp[k][t]);
}
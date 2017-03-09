#include <cstdio>
#include <cstring>

#define MAX(a,b) (((a)>(b))?(a):(b))

char a[1001];
char b[1001];
int dp[1001][1001];

int main()
{
	scanf("%s %s",a,b);
	int l1 = strlen(a);
	int l2 = strlen(b);

	for(int i=0;i<=l1;++i) dp[i][0]=0;
	for(int i=0;i<=l2;++i) dp[0][i]=0;

	for(int i=1;i<=l1;++i){
		for(int j=1;j<=l2;++j){
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=MAX(dp[i-1][j],dp[i][j-1]);
		}
	}

	printf("%d\n",dp[l1][l2]);
}
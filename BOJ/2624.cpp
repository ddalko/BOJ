#include <cstdio>
#include <algorithm>

using namespace std;

struct coin{
	int p;
	int n;

	bool operator < (const coin rhs) const
	{
		if(p != rhs.p) return p < rhs.p;
		return n < rhs.n;
	}
};

int T, k;
coin c[105];
int dp[2][10005];

int main()
{
	scanf("%d %d",&T,&k);
	for(int i = 0; i < k; ++i) {
		scanf("%d %d",&c[i].p,&c[i].n);
	}
	sort(c, c + k);

	dp[0][0] = 1;
	for(int i = 0; i < k; ++i){
		for(int j = 0; j <= c[i].n; ++j){
			for(int l = 0; l <= T; ++l){
				if(l + c[i].p * j > T) break;
				dp[(i+1)%2][l + j * c[i].p] += dp[i%2][l];
			}
		}
	}

	printf("%d\n", dp[k%2][T]);
}
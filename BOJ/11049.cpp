#include <cstdio>

#define MIN(a,b) (((a)<(b))?(a):(b))

typedef struct {
	int x,y;
}Matrix;

int n;
Matrix m[501];
int dp[501][501];

int mult(Matrix a,Matrix b){
	return (a.y==b.x) ? a.x*b.x*b.y : 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		m[i].x = a;
		m[i].y = b;
	}

	for(int j=0;j<n-1;++j){
		for(int i=0;i<n-j-1;++i){
			int m1=mult(m[j+i],m[j+i+1]);
			int m2=mult(m[i],m[i+1]);
			printf("%d %d\n",m1,m2);
			dp[i][j+i+1]=MIN(dp[i][j+i]+m1,dp[i+1][j+i+1]+m2);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j) printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("%d\n",dp[0][n-1]);
}
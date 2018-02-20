#include <cstdio>

int n,w,l;
int W[1001];

int main()
{
	int ans = 0;
	int curWeight = 0; int curLen = 0;
	scanf("%d %d %d",&n,&w,&l);
	for(int i = 0; i < n; ++i) scanf("%d",W + i);

	for(int i = 0; i < n; ++i){
		while(curWeight < w && curLen <= l){
			
		}
		
	}
	
	
	if(curWeight > 0 || curLen > 0){

	}

	printf("%d\n", ans);
}
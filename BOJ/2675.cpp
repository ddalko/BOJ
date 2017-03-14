#include <cstdio>

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		char inp[20];
		int r;
		scanf("%d %s",&r,inp);
		for(int i=0;inp[i];++i) for(int j=0;j<r;++j) printf("%c",inp[i]);
		printf("\n");
	}
}
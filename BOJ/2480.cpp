#include <cstdio>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int main()
{
	int ans = 0;
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);

	if(a == b && b == c){
		ans = 10000 + a * 1000;
	}else if(a == b){
		ans = 1000 + a * 100;
	}else if(b == c){
		ans = 1000 + b * 100;
	}else if(a == c){
		ans = 1000 + c * 100;
	}else{
		ans = max(a,(max(b, c))) * 100;
	}
	printf("%d\n",ans);
}
#include <cstdio>

int n;
char s[2002];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf(" %c",s+i);

	int cnt = 0;
	int l = 0, r = n-1;

	while(l <= r){
		bool left = true;
		for(int i = 0; i+l <= r; ++i){
			if(s[l+i] < s[r-i]){
				left = true;
				break;
			}else if(s[l+i] > s[r-i]){
				left = false;
				break;
			}
		}
		if(left) putchar(s[l++]);
		else putchar(s[r--]);
		cnt++;
		if(cnt % 80 == 0) putchar('\n');
	}
	putchar('\n');
}
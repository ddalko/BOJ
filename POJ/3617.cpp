#include <cstdio>

int n;
char s[2003];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf(" %c",s+i);

	int l = 0; int r = n-1;
	int cnt = 0;

	while(l <= r){
		bool left = false;

		for(int i = 0; l + i <= r; i++){
			if(s[l+i] > s[r-i]){
				left = false;
				break;
			}else if(s[l+i] < s[r-i]){
				left = true;
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
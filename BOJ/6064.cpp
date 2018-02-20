#include <cstdio>

int m, n, x, y;

int lcm(int a, int b)
{
	int m, n;
	m = a;
	n = b;
	while(m != n){
		if(m < n) m = m+a;
		else n = n+b;
	}
	return m;
}

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d %d",&m,&n,&x,&y);	

		int L = lcm(m, n);
		int cnt = 1;
		int tx = 1; int ty = 1;
		bool ans = false;

		while(tx != x && ty != y){
			tx++; ty++; cnt++;
		}

		while(cnt <= L){
			if(tx == x && ty == y){
				printf("%d\n", cnt);
				ans = true;
				break;
			}
			if(tx == x){
				if((ty+m) % n == 0) ty = n;
				else ty = (ty+m)%n;
				cnt += m;
			}else if(ty == y){
				if((tx+n) % m == 0) tx = m;
				else tx = (tx+n)%m;
				cnt += n;
			}
		}

		if(!ans) puts("-1");
	}
}
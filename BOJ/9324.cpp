#include <cstdio>

int chk[26];
char inp[100005];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		for(int i = 0; i < 26; ++i) chk[i] = 0;
		scanf("%s",inp);

		bool ans = true;
		for(int i = 0; inp[i]; ++i){
			chk[inp[i]-'A']++;
			if(chk[inp[i]-'A'] % 3 == 0){
				if(!inp[i] || inp[i+1] != inp[i]){
					ans = false;
					break;
				}
				++i;
			}
		}
		if(ans) puts("OK");
		else puts("FAKE");
	}
}
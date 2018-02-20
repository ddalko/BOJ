#include <vector>
#include <cstdio>

using namespace std;

vector<int> b[65];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		int a;
		scanf("%d",&a);

		bool ans;
		for(int i = 2; i < 65; ++i) b[i].clear();

		for(int i = 2; i < 65; ++i){
			ans = true;
			int tmp = a;

			while(tmp){
				b[i].push_back(tmp % i);
				tmp /= i;
			}

			int len = b[i].size();
			for(int k = 0; k < len / 2; ++k){
				if(b[i][k] != b[i][len-k-1]) {
					ans = false;
					break;
				}
			}	

			if(ans) {
				printf("1\n");
				break;
			}	
		}
		if(!ans) printf("0\n");
	}
}
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

int n;
vector<pii> S;

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d",&a,&b);
		S.push_back(make_pair(b, a));
	}
	sort(S.begin(), S.end());

	int ans = 0;
	int e = 0;
	for(int i = 0; i < n; ++i){
		if(S[i].second >= e){
			e = S[i].first;
			ans++;
		}
	}
	printf("%d\n", ans);
}
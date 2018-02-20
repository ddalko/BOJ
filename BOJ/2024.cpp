#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m;
vector<pair<int,int> > v;

int main()
{
	int li, ri;
	scanf("%d",&m);
	while(scanf("%d %d",&li,&ri)){
		if(li == 0 && ri == 0) break;
		v.push_back(make_pair(li, ri));
	}
	sort(v.begin(), v.end());

	int n = v.size(); int ans = 0;
	int idx = 0; int s = 0;

	while(s < m && idx < n){
		int longest = -1e9;
		while(idx < n && v[idx].first <= s) {
			longest = max(longest, v[idx].second);
			idx++;
		}
		if(longest == -1e9) break;
		s = longest;
		ans++;
	}
	printf("%d\n",s >= m ? ans : 0);
}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int n, d;
int a[MAXN+1]; int b[MAXN+1];
vector<pair<int,int> > H;


int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d",&x,&y);
		a[i] = min(x, y);
		b[i] = max(x, y);
	}
	scanf("%d",&d);

	for(int i = 0; i < n; ++i){
		if(b[i] - a[i] > d) continue;
		else H.push_back(make_pair(a[i], b[i]));
	}

	sort(H.begin(), H.end());

	int cnt = 0; int ans = 0; int s = 0;
	if(H.size()!=0) s = H[0].first;

	for(int i = 0; i < H.size(); ++i){
		if(H[i].second - s <= d){
			cnt++;
		}else{
			ans = max(ans, cnt);
			s = H[i].first;
			cnt = 1;
		}
	}

	printf("%d\n",ans);
}
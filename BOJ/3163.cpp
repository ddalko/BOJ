#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100000;

int n, l, k;

struct Ant
{
	int pos;
	int id;
};

bool cmp(const Ant lhs, const Ant rhs)
{
	int a = (lhs.id > 0) ? (l - lhs.pos) : lhs.pos;
	int b = (rhs.id > 0) ? (l - rhs.pos) : rhs.pos;
	if(a != b) return a < b;
	return abs(lhs.id) < abs(rhs.id);
}

Ant A[MAXN+1];
int ID[MAXN+1];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d",&n,&l,&k);

		for(int i = 0; i < n; ++i){
			scanf("%d %d",&A[i].pos,&A[i].id);
			ID[i] = A[i].id;
		}
		sort(A, A+n, cmp);

		vector<pair<int,int> > ans;
		int left = 0; int right = n-1;
		for(int i = 0; i < n; ++i){
			int dist = (A[i].id > 0) ? (l - A[i].pos) : A[i].pos;

			if(A[i].id > 0){
				ans.push_back(make_pair(dist, ID[right--]));
			}else{
				ans.push_back(make_pair(dist, ID[left++]));
			}
		}
		sort(ans.begin(), ans.end());

		printf("%d\n", ans[k-1].second);
	}	
}
#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;

int n,m,k;
bool s[100001];
int dist[100001];
vector<pair<int,int> > g[100005];

void dijkstra(int node)
{
	priority_queue<pair<int,int> > pq;

	dist[node]=0;
	pq.push(make_pair(0,node));

	whlie(!pq.empty()){
		for(int nxt=0;nxt<g[node].size();++nxt){
			//g[node][nxt].first->node

		}
	}
}	

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<m;++i) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			g[a].push_back(make_pair(b,c));
			g[b].push_back(make_pair(a,c));
		}		
		for(int i=0;i<k;++i) {
			int a;
			scanf("%d",&a);
			s[a]=true;			
		}

		int ans=0;
		int ans2=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n;++j) dist[j]=INF;
			dijkstra(i);
			int minDist=INF;
			for(int j=1;j<=n;++j) {
				if(j==i) continue;
				if(s[i]) {
					if(minDist>dist[i]) {
						minDist=dist[i];
						ans+=minDist;
						ans2+=i;
					}
				} 
			}
		}
		printf("Case #%d\n", test_case);
		printf("%d\n",ans);
		printf("%d\n",ans2);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
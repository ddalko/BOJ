#include <cstdio>

const int MAXN = 10001;

typedef struct{
	int a,b;
	int c;
}Edge;

typedef struct{
	int first;
	int second;
}Pair;

int n,m,x;
int dist1[1001];
int dist2[1001];
Edge tmp[10000];
Edge e1[10000];
Edge e2[10000];
Pair nodeInfo1[1001];
Pair nodeInfo2[1001];

void msort1(int l, int r)
{
	if(l == r) return ;
	int m = (l + r) / 2;
	msort1(l, m);
	msort1(m + 1, r);

	int p = l; int lp = l; int rp = m + 1;
	while(lp <= m && rp <= r) {
		if(e1[lp].a <= e1[rp].a) tmp[p++] = e1[lp++];
		else tmp[p++] = e1[rp++];
	}
	while(lp <= m) tmp[p++] = e1[lp++];
	while(rp <= r) tmp[p++] = e1[rp++];

	for (int i = l; i <= r; ++i) e1[i] = tmp[i];
}

void msort2(int l, int r)
{
	if(l == r) return ;
	int m = (l + r) / 2;
	msort2(l, m);
	msort2(m + 1, r);

	int p = l; int lp = l; int rp = m + 1;
	while(lp <= m && rp <= r) {
		if(e2[lp].a <= e2[rp].a) tmp[p++] = e2[lp++];
		else tmp[p++] = e2[rp++];
	}
	while(lp <= m) tmp[p++] = e2[lp++];
	while(rp <= r) tmp[p++] = e2[rp++];

	for (int i = l; i <= r; ++i) e2[i] = tmp[i];
}

void dijkstra(int node)
{

}

int main()
{
	scanf("%d %d %d",&n,&m,&x);
	
	for(int i = 0; i <= n; ++i) dist1[i] = dist2[i] = INF;

	for(int i = 0; i < m; ++i){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		e1[i].a = b; e1[i].b = a; e1[i].c = c;
		e2[i].a = a; e2[i].b = b; e2[i].c = c;
	}
	msort1(0, m-1);
	msort2(0, m-1);

	int idx = 0;
	for(int i = 1; i <= n; ++i){
		nodeInfo1[i].first = idx++;
		while(e1[idx].a == i) idx++;
		nodeInfo1[i].second = idx-1;
	}

	idx = 0;
	for(int i = 1; i <= n; ++i){
		nodeInfo2[i].first = idx;
		while(e2[idx].a == i) idx++;
		nodeInfo2[i].second = idx-1;
	}

	int d
}
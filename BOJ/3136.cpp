#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
string inp;
set<pii> v;
set<pair<pii, pii> > e;

int main()
{
    cin >> n >> inp;
    int len = inp.size();
    int cx = 0, cy = 0;
    v.insert(mp(cx, cy));

    for(int i = 0; i < len ; ++i){
        for(int j = 0; j < 2; ++j){
            int nx = cx + dx[inp[i]-'0'];
            int ny = cy + dy[inp[i]-'0'];
            pii cur(cx, cy);
            pii nxt(nx, ny);
            v.insert(nxt);
            e.insert(mp(min(cur, nxt), max(cur, nxt)));
            cx = nx;
            cy = ny;
        }        
    }
    printf("%d\n", 1 - v.size() + e.size());
}
#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef pair<lld,lld> pll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int l, n, pidx;
pll p[2005];

lld cross(lld cx, lld cy, lld nx, lld ny, lld dir)
{
    lld ret = 2e18;

    if(dir % 2 == 0){
        for(int j = 0; j < pidx-2; ++j){
            bool chk1 = false, chk2 = false;
            if(min(cx, nx) <= p[j].first && p[j].first <= max(cx, nx)) chk1 = true;
            if(min(p[j].second, p[j+1].second) <= cy && cy <= max(p[j].second, p[j+1].second)) chk2 = true;
            if(chk1 & chk2) ret = min(ret, max(p[j].first, cx) - min(p[j].first, cx));
        }
    }else{
        for(int j = 0; j < pidx-2; ++j){
            bool chk1 = false, chk2 = false;
            if(min(cy, ny) <= p[j].second && p[j].second <= max(cy, ny)) chk1 = true;
            if(min(p[j].first, p[j+1].first) <= cx && cx <= max(p[j].first, p[j+1].first)) chk2 = true;
            if(chk1 & chk2) ret = min(ret, max(p[j].second, cy) - min(p[j].second, cy));
        }
    }

    return ret;
}

int main()
{
    cin >> l;
    cin >> n;

    int dir = 0;
    lld cx = 0, cy = 0;
    lld ans = 0;
    bool flag = false;
    p[0].first = 0; p[0].second = 0;
    pidx = 1;

    for(int i = 0; i < n; ++i){
        int t; char d;
        cin >> t >> d;

        lld nx = cx + dx[dir] * (lld)t;
        lld ny = cy + dy[dir] * (lld)t;

        lld dist = cross(cx, cy, nx, ny, dir);

        if(dist != 2e18) {
            ans += dist;
            flag = true;
            break;
        }

        if(nx <= -l || l <= nx) {
            ans += l - cx + 1;  
            flag = true;  
            break;
        }

        if(ny <= -l || l <= ny) {
            ans += l - cy + 1;
            flag = true;
            break;
        }

        cx = nx; cy = ny;
        p[pidx].first = cx; p[pidx].second = cy;
        pidx++;
        
        if(d == 'L') dir = (dir + 3) % 4;
        else if(d == 'R') dir = (dir + 1) % 4;

        ans += t;
    }
    
    if(!flag) {
        if(dir % 2 == 0) ans += l - cx + 1;
        else ans += l - cy + 1;
    }

    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    const bool operator < (const Point rhs)
    {
        if(x != rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};

int n;
Point p[100005];

inline int dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

//return minimum dist from range(s ~ e)
int f(int s, int e)
{
    if(s == e) return 1e9;

    int m = (s + e) / 2;
    int mdist = min(f(s, m), f(m+1, e));

    vector<Point> l;
    vector<Point> r;
    for(int i = 0; i <= m; ++i) l.push_back(p[i]);
    for(int i = m+1; i <= e; ++i) r.push_back(p[i]);
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    
    return mdist;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        p[i].x = a; p[i].y = b;
    }
    sort(p, p+n);
    printf("%d\n", f(0, n-1));
}
#include <cstdio>
#include <algorithm>

using namespace std;

struct P{
    int x, y;

    bool operator < (const P rhs) const
    {
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};

int n;
P p[100005];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        p[i].x = a; p[i].y = b;
    }
    sort(p, p+n);
    for(int i = 0; i < n ; ++i) printf("%d %d\n",p[i].x,p[i].y);
}
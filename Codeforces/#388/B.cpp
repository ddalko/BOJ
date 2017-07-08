#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;

int main()
{
    pii a;
    pii b;
    pii c;
    scanf("%d %d", &a.first, &a.second);
    scanf("%d %d", &b.first, &b.second);
    scanf("%d %d", &c.first, &c.second);
        
    vector<pii> ans;
    ans.push_back(make_pair(b.first + c.first - a.first, b.second + c.second - a.second));
    ans.push_back(make_pair(c.first + a.first - b.first, c.second + a.second - b.second));
    ans.push_back(make_pair(b.first + a.first - c.first, b.second + a.second - c.second));

    printf("%d\n",(int)ans.size());
    for(int i = 0; i < (int)ans.size(); ++i){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}
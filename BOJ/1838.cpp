#include <algorithm>
#include <vector>

using namespace std;

int n, x;
vector<pair<int,int> > arr;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&x);
        arr.emplace_back(make_pair(x, i));
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, arr[i].second-i-1);
    }
    printf("%d\n",ans);
}
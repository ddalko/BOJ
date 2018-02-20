#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    vector<int> ans;
    while(n)
    {
        if(n % 2){
            n -= 3;
            ans.push_back(3);
        }else{
            n -= 2;
            ans.push_back(2);
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i = 0; i < (int)ans.size(); ++i) printf("%d ",ans[i]);
}
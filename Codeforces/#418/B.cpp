#include <cstdio>
#include <vector>

using namespace std;

int n;
int a[1005];
int b[1005];
int p1[1005];
int p2[1005];

bool chk[1005];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d",a+i);
    for(int i = 0; i < n; ++i) scanf("%d",b+i);
    
    vector<int> pidx;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == b[i]) {
            p1[i] = a[i];
            p2[i] = a[i];
            chk[p1[i]] = true;
        }
        else{
            pidx.push_back(i);
        }
    }

    vector<int> abidx;
    for(int i = 1; i <= n; ++i){
        if(!chk[i]) abidx.push_back(i);
    }

    if((int)pidx.size() == 1){
        p1[pidx[0]] = abidx[0];
        for(int i = 0; i < n; ++i){
            printf("%d ",p1[i]);
        }
        puts("");
        return 0;
    }

    p1[pidx[0]] = abidx[0];
    p1[pidx[1]] = abidx[1];

    //chk p1;
    int chka = 0; int chkb = 0;
    for(int i = 0; i < n; ++i){
        if(p1[i] != a[i]) chka++;
        if(p1[i] != b[i]) chkb++;
    }
    if(chka == 1 && chkb == 1){
        for(int i = 0; i < n; ++i){
            printf("%d ",p1[i]);
        }
        puts("");
        return 0;
    }

    p2[pidx[1]] = abidx[0];
    p2[pidx[0]] = abidx[1];

    for(int i = 0; i < n; ++i){
        printf("%d ",p2[i]);
    }
    puts("");
    return 0;
}
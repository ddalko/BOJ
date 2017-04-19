#include <cstdio>
#include <cmath>

int n, k;
double cable[10005];

bool decision(double x)
{
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt += (int)(cable[i] / x);
    }
    return cnt >= k;
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; ++i) scanf("%lf",cable+i);
    
    double l = 0; double r = 1e7;
    while(r - l > 0.0000001){
        double m = (l + r) / 2;
        if(decision(m)) l = m;
        else r = m;
    }     
    printf("%.2f\n",round(r));
}
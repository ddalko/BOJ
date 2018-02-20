#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int A[4005];
int B[4005];
int C[4005];
int D[4005];
int AB[4005*4005];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            AB[i*n+j] = A[i] + B[j];
        }
    }
    sort(AB, AB+n*n);

    long long ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int cd = -(C[i] + D[j]);
            ans += upper_bound(AB, AB+n*n, cd) - lower_bound(AB, AB+n*n, cd);
        }
    }
    printf("%lld\n",ans);
}
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1005];

int main()
{
    int n;
    scanf("%d ",&n);
    
    int m = -1e9;
    for(int i = 0; i < n; ++i){
        scanf("%d ", arr+i);
        m = max(m, arr[i]);
    }

    double dsum = 0;
    for(int i = 0; i < n; ++i){
        dsum += arr[i] / (double)m * 100.0;
    }
    printf("%.2f\n", dsum / n);
}
#include <cstdio>

int n, a, b;
int d[505];
int m[505][505];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d",&a,&b);
        d[i] = a;
        d[i+1] = b;
    }

    for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) { m[i][j] = -1; m[i][i] = 0; }

    for(int k = 1; k < n; ++k){
        for(int i = 0; i < n - k; ++i){
            for(int j = 0; j < k; ++j){
                int c = m[i][i+j] + m[i+j+1][i+k] + d[i] * d[i+j+1] * d[i+k+1];
                if(m[i][i+k] == -1 || m[i][i+k] > c) m[i][i+k] = c;
            }
        }
    }
    printf("%d\n", m[0][n-1]);
}
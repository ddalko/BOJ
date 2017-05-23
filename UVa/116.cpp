#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long lld;
int n, m;
int g[101][101];
bool f[101][101];
lld dp[101][101];


void asmin(lld& a, lld b) {
    if (a > b) a = b;
}

int mod(int a, int n) {
    return (a % n + n) % n;
}
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &g[i][j]);
                f[i][j] = 0;
            }
        }
        const lld INF = (lld)1e18;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = INF;
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                for (int k = -1; k <= 1; ++k) {
                    int ni = mod(i+k, n);
                    int nj = j+1;
                    asmin(dp[ni][nj], dp[i][j] + g[ni][nj]);
                }
            }
        }
        lld ans = INF;
        for (int i = 0; i < n; ++i) ans = min(ans, dp[i][m]);
        for (int i = 0; i < n; ++i) {
            if (dp[i][m] == ans) f[i][m] = 1;
        }
        for (int j = m - 1; j >= 1; --j) {
            for (int i = 0; i < n; ++i) {
                for (int k = -1; k <= 1; ++k) {
                    int ni = mod(i+k, n);
                    int nj = j+1;
                    if (dp[ni][nj] == dp[i][j] + g[ni][nj]) f[i][j] |= f[ni][nj];
                }
            }
        }
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            if (f[i][1]) {
                cur = i;
                break;
            }
        }
        printf("%d", cur+1);
        for (int j = 1; j < m; ++j) {
            int nxt = n;
            for (int k = -1; k <= 1; ++k) {
                int ni = mod(cur+k, n);
                int nj = j+1;
                if (f[ni][nj] && dp[cur][j] + g[ni][nj] == dp[ni][nj]) {
                    nxt = min(nxt, ni);
                }
            }
            cur = nxt;
            printf(" %d", cur+1);
        }
        puts("");
        printf("%lld\n", ans);
    }
}
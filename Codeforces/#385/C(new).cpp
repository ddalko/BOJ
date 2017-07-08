#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int p[1005];
int sz[1005];
int e[1005];
int is_go[1005];
int n, m, k;

int par(int x) {
  return x == p[x] ? x : (p[x] = par(p[x]));
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    is_go[x] = true;
  }

  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    sz[i] = 1;
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = par(u);
    v = par(v);
    if (u == v) {
      e[u]++;
      continue;
    }
    p[u] = v;
    sz[v] += sz[u];
    e[v] += e[u] + 1;
    is_go[v] |= is_go[u];
  }
  
  int ans = 0;
  int bsz = 0, be = 0;
  priority_queue<int> A, B;
  for (int i = 1; i <= n; ++i) {
    if (i == par(i)) {
      int c = sz[i] * (sz[i] - 1) / 2 - e[i];
      ans += c;
      e[i] += c;
      if (is_go[i]) {
        A.push(sz[i]);
      } else {
        bsz += sz[i];
        be += e[i];
      }
    }
  }

  if (!A.empty()) {
    ans += bsz * (bsz - 1) / 2 - be;
    int a = A.top();
    ans += a * bsz;
  }
  printf("%d\n", ans);
}
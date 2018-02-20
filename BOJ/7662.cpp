#include <cstdio>
#include <set>

using namespace std;

int main() {
    int t, k;
    char op; int inp;
    for (scanf("%d", &t); t--;) {
        multiset<int> ms;
        for (scanf("%d", &k); k--;) {
            scanf(" %c %d",&op,&inp);
            if (op == 'I') ms.insert(inp);
            else if (!ms.empty()) inp < 0 ? ms.erase(ms.begin()) : ms.erase(--ms.end());
        }
        if(ms.empty()) puts("EMPTY");
        else printf("%d %d\n",*ms.rbegin(), *ms.begin());
    }
}
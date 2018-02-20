#include <cstdio>
#include <queue>

using namespace std;

const int MOD = 20090711;
const int A0 = 1983;

typedef long long lld;

int n, a, b;

int create(int inp)
{
	return (inp * (lld)a + b) % MOD;
}

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d",&n,&a,&b);

		priority_queue<lld> minH;
		priority_queue<lld> maxH;

		int sum = 0; int t = A0;
		for(int i = 0; i < n; ++i){
			if(minH.size() == maxH.size()){
				maxH.push(t);
			}else {
				minH.push(-t);
			}
			if(!minH.empty() && !maxH.empty() && maxH.top() > -minH.top()){
				int minTop = -minH.top();
				int maxTop = maxH.top();
				minH.pop(); maxH.pop();
				maxH.push(minTop); minH.push(-maxTop);
			}
			sum = (sum + maxH.top()) % MOD;
			t = create(t);
		}
		printf("%d\n", sum);
	}
}
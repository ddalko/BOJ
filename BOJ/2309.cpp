#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;

int arr[9];
int tmp[9];
bool flag = false;

void msort(int l, int r)
{
	if(l == r) return ;
	int m = (l + r) / 2;
	msort(l, m);
	msort(m+1, r);

	int p = l;
	int lp = l; int rp = m+1;

	while(lp <= m && rp <= r){
		if(arr[lp] <= arr[rp]) tmp[p++] = arr[lp++];
		else tmp[p++] = arr[rp++];
	}
	while(lp <= m) tmp[p++] = arr[lp++];
	while(rp <= r) tmp[p++] = arr[rp++];

	for(int i = l; i <= r; ++i) arr[i] = tmp[i];
}

void f(int idx,vector<int>& s)
{
    int num = s.size();
    int sum = 0;
    for(int i=0;i<num;++i) sum += s[i];

    if(num == 7 && sum == 100 && !flag) {
        for(int i=0;i<s.size();++i) printf("%d\n",s[i]);
        flag = true;
        return ;
    }
    if(idx > 9) return ;
    if(sum > 100) return ;

    s.push_back(arr[idx]);
    f(idx+1,s);
    s.pop_back();
    f(idx+1,s);
}

int main()
{
	for(int i = 0; i < 9; ++i) scanf("%d",arr+i);
	msort(0, 8);

	vector<int> ans;
	f(0, ans);	
}
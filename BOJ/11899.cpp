#include <cstdio>
#include <vector>

using namespace std;

char inp[51];
vector<char> v;

int main()
{
	scanf("%s",inp);

	for(int i = 0; inp[i]; ++i){
		if(inp[i] == '(') {
			v.push_back(inp[i]);
		}else if(inp[i] == ')'){
			if(!v.empty() && v.back() == '('){
				v.pop_back();
			}else{
				v.push_back(inp[i]);
			}
		}
	}
	printf("%d\n",v.size());
}
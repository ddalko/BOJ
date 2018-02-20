#include <cstdio>
#include <cstring>
#include <algorithm>

int len;
int nxt;
int deep;
char eof[3] = "()";
char inp[32005];

bool f(int idx, int lvl)
{
	bool ret;
	if(lvl%2 == deep%2){
		ret = true;
		for(nxt = idx; nxt < len; ++nxt){
			if(inp[nxt] == '('){
				ret = ret * f(nxt+1, lvl+1);
			}else if(inp[nxt] == ')'){
				return ret;
			}else if(inp[nxt] == 'F'){
				ret = 0;
			}
		}
	}
	else{
		ret = false;
		for(nxt = idx; nxt < len; ++nxt){
			if(inp[nxt] == '('){
				ret = ret + f(nxt+1, lvl+1);
			}else if(inp[nxt] == ')'){
				return ret;
			}else if(inp[nxt] == 'T'){
				ret = 1;
			}
		}
	}
	return ret;
}

int main()
{
	int ans = 1;
	while(scanf("%s",inp), strcmp(inp, eof))
	{
		deep = -1e9;
		len = strlen(inp);
		int lv = 0;
		for(int i = 0; i < len; ++i){
			if(inp[i] == '(') {
				lv++;
				deep = std::max(deep, lv);
			}else if(inp[i] == ')') lv--;
		}
		if(f(0, 0)) printf("%d. true\n",ans++);
		else printf("%d. false\n",ans++);
	}	
}
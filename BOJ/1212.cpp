#include <bits/stdc++.h>

using namespace std;

string inp;
string ans;

int main()
{
    cin>>inp;
    int len=inp.size();

    if(inp[0]=='7') ans="111";
	else if(inp[0]=='6') ans="110";
	else if(inp[0]=='5') ans="101";
	else if(inp[0]=='4') ans="100";
	else if(inp[0]=='3') ans="11";
	else if(inp[0]=='2') ans="10";
	else if(inp[0]=='1') ans="1";
	else ans="0";

    for(int i=1;i<len;++i){
    	if(inp[i]=='7') ans+="111";
		else if(inp[i]=='6') ans+="110";
		else if(inp[i]=='5') ans+="101";
		else if(inp[i]=='4') ans+="100";
		else if(inp[i]=='3') ans+="011";
		else if(inp[i]=='2') ans+="010";
		else if(inp[i]=='1') ans+="001";
		else ans+="000";
    }
    cout<<ans<<'\n';
}
#include <bits/stdc++.h>

using namespace std;

string inp;

string octTobin(string s)
{
	if(s == "111"){
		return "7";
	}else if(s == "110"){
		return "6";
	}else if(s == "101"){
		return "5";
	}else if(s == "100"){
		return "4";
	}else if(s == "011"){
		return "3";
	}else if(s == "11"){
		return "3";
	}else if(s == "010"){
		return "2";
	}else if(s == "10"){
		return "2";
	}else if(s == "001"){
		return "1";
	}else if(s == "1"){
		return "1";
	}else if(s == "000"){
		return "0";
	}else if(s == "0"){
		return "0";
	}
}

int main()
{
	string out;
	cin >> inp;
	int len = inp.size();
	if(len < 4){
		out = octTobin(inp);
	}
	else{
		for(int i = 0; i + 3 < len; i += 3){
			out += octTobin( inp.substr(i, i+3) );
		}	
	}
	cout << out << '\n';
}
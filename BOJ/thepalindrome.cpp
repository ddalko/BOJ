#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inp;
	cin >> inp;

	int len = inp.length();
	for(int i = 0; i < len; ++i){

		bool flag = true;
		for(int j = 0; j < (len + i) / 2; ++j){
			if(j < i) continue;

			if(inp[j] != inp[len+i-1-j]){
				flag = false;
				break;
			}
		}

		if(flag){
			cout << len + i << endl;
			return 0;
		}
	}
}
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
    int len;
    string inp;
    vector<char> stk;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        len = 0;
        stk.clear();

        cin >> inp;

        for(int i = 0; i < inp.length(); ++i){
            if(inp[i] == '(' || inp[i] == '{' || inp[i] == '['){
                stk.push_back(inp[i]);
            }else{
                if(stk.empty()){
                    len = 0;
                    continue;
                } 

                char top = stk.back();
                bool cmp1 = (top == '(' && inp[i] == ')') ? 1 : 0;
                bool cmp2 = (top == '[' && inp[i] == ']') ? 1 : 0;
                bool cmp3 = (top == '{' && inp[i] == '}') ? 1 : 0;

                if(cmp1 || cmp2 || cmp3)
                {
                    len += 2;
                    stk.pop_back();
                    if(stk.empty()) Answer = max(Answer, len);
                }else{
                    stk.clear();
                    len = 0;
                    Answer = max(Answer, len);
                }
            }
        }

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
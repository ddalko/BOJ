#include <iostream>

using namespace std;

int Answer;
int price[200005];

int main(int argc, char** argv)
{
	int T, test_case;
    int n;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> price[i];

        bool flag = false;
        
        for(int i = 1; i < n; ++i){
            if(price[i-1] < price[i]){
                if(!flag) flag = true;
                if(i == n-1) Answer += 2;
            }else if(price[i-1] > price[i]){
                if(flag) {
                    Answer += 2;
                    flag = false;
                }
            }
        }
        
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
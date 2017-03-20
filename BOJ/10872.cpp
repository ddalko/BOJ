#include <iostream>
#include <string>

using namespace std;

string out[13] = {"1","1","2","6","24","120","720","5040",
		"40320", "362880", "3628800", "39916800", "479001600"};

int main()
{
	int n;
	cin >> n;
	cout << out[n] << '\n';
}
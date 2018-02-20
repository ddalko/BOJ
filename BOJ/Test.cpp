#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string data = "BNeweYork";
	
	transform(data.begin(), data.end(), data.begin(), ::tolower);

	cout << data << endl;
}
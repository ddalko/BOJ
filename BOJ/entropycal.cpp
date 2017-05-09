#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d",&a,&b);
    double result = 0;

    double x = a * log2(a);
    double y = b * log2(b);
    double xx = a * log2(a+b);
    double yy = b * log2(a+b);

    double d = -x -y +xx +yy;
    double dd = a+b;

    result = d / dd;
    cout << result << endl;
}
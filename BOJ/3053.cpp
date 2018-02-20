#include <cstdio>
#include <cmath>

using namespace std;

const double PI = 2.0 * acos(0.0);

int main()
{
    int r;
    scanf("%d",&r);
    printf("%.6lf\n", r*r*PI);
    printf("%.6lf\n", r*r*2.0);
}
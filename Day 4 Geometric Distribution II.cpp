#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


float geometric( float p, int k)
{
    return pow( 1 - p , k - 1 ) * p ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ;
    float a , b , P;
    cin >> a >> b >> n;
    float p = a / b;
    for (int k = 1; k <= n; k++)
    {
        P += geometric( p , k ) ;
    }
    cout << (float) round ( P * 1000 ) / 1000 << endl;
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long factorial ( int n )
{
    n++;
    long ret = 1;
    while (n-- > 1)
        ret *= n;
    return (ret);
};

long comb (int n , int k)
{
    if ( k <= n )
        return ( factorial (n) / factorial (k) / factorial ( n - k) );
    else
        return ( 0 ) ;
}

float binomial ( int n , int k , float p )
{
    return ( pow ( p , k ) * pow ( 1 - p , n - k ) * comb ( n , k ) ) ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float p;
    int n ;
    cin >> p >> n;
    p /= 100;
    cout << (float) round ( ( binomial( n , 0 , p ) + binomial( n , 1 , p ) + binomial( n , 2 , p ) ) * 1000 ) / 1000 << endl;
    cout << (float) round ( ( 1 - binomial(n, 0 , p) - binomial( n , 1 , p ) ) * 1000 ) / 1000 << endl;
    return 0;
}

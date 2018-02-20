#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float a , b ;
    int k = 2 , n = 6;
    cin >> a >> b ;
    float P = 0;
    while ( k++ < n )
    {
        P += ( pow ( a , k ) * pow ( b , n - k ) ) * comb ( n , k ) ;
    }
    cout << (float) round ( P / pow ( a + b , n ) * 1000 ) / 1000 << endl;
    return 0;
}

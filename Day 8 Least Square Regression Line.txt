#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 5 ;
    // cin >> n ;
    vector < float > X ( n ) ;
    vector < float > Y ( n ) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> X[i] >> Y[i] ;
    // sum xi
    float sumxi = accumulate( X.begin() , X.end() , 0.0 ) ;
    // sum yi
    float sumyi = accumulate( Y.begin() , Y.end() , 0.0 ) ;
    // sum ( xi * yi)
    float sumxiyi = inner_product ( X.begin() , X.end() , Y.begin() , 0) ;
    // sum ( xi ) * sum ( yi )
    float sumxisumyi = accumulate( X.begin() , X.end() , 0.0 ) * accumulate( Y.begin() , Y.end() , 0 ) ;
    // sum ( xi ^ 2 )
    float sum_xi2 = accumulate( X.begin() , X.end() , (float) 0.0 , [] ( float &s, float &x ) { return ( s + x * x ) ; } ) ;
    // sum ( xi ) ^ 2
    float sumxi2 = pow( sumxi , 2 ) ;
    // Calculate b
    float b = ( sumxiyi * n - sumxi * sumyi ) / ( sum_xi2 * n - sumxi2 ) ;
    // Calculate mean ( x )
    float meanX = sumxi / n ;
    // Calculate mean ( y )
    float meanY = sumyi / n ;
    // Calculate a
    float a = meanY - b * meanX ;
    // Calculate y for x = 80
    float y = a + b * 80.0 ;
    cout << (float) round ( y * 1000 ) / 1000 << endl ;
    return 0;
}


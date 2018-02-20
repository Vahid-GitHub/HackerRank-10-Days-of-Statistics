#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ;
    cin >> n ;
    vector < float > X ( n ) , X_normal ( n );
    vector < float > Y ( n ) , Y_normal ( Y );
    for_each ( X.begin() , X.end() , [] ( float &x ) { cin >> x ; } ) ;
    for_each ( Y.begin() , Y.end() , [] ( float &y ) { cin >> y ; } ) ;
    float mu_X = accumulate ( X.begin() , X.end() , 0.0 ) / X.size() ;
    float mu_Y = accumulate ( Y.begin() , Y.end() , 0.0 ) / Y.size() ;
    transform ( X.begin() , X.end() , X_normal.begin() , [mu_X] ( float &x ) { return ( x - mu_X ); } ) ;
    transform ( Y.begin() , Y.end() , Y_normal.begin() , [mu_Y] ( float &y ) { return ( y - mu_Y ); } ) ;
    float var_X = accumulate ( X_normal.begin() , X_normal.end() , (float) 0.0 , [] ( float &s , float &x ) { return ( s + x * x ); }) / X_normal.size() ;
    float var_Y = accumulate ( Y_normal.begin() , Y_normal.end() , (float) 0.0 , [] ( float &s , float &y ) { return ( s + y * y ); }) / Y_normal.size() ;
    float cov = inner_product( X_normal.begin() , X_normal.end() , Y_normal.begin() , 0 ) / n ;
    float pearson_correlation_coefficient = cov / sqrt ( var_X ) / sqrt ( var_Y ) ;
    cout << (float) round ( pearson_correlation_coefficient * 100 ) / 100 << endl ;
    return 0;
}


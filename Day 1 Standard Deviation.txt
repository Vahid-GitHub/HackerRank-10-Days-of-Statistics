#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N ;
    cin >> N ;
    vector < int > X ( N ) ;
    for_each ( X.begin() , X.end() , [] ( int &x ) { cin >> x ; } ) ;
    float mu = (float) accumulate( X.begin() , X.end() , 0 ) / X.size() ;
    float sigma2 = accumulate( X.begin() , X.end() , 0.0 ,
                                    [mu] (double &s , int &x) {
                                            return ( s + ( x - mu ) * ( x - mu ) ) ;
                                            } ) / X.size() ;
    cout << round( sqrt(sigma2) * 10 ) / 10 << endl;
    return 0;
}

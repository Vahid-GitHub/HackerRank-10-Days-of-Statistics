#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector<int> X( N );
    // Reading input
    for_each ( X.begin() , X.end() , [] ( int &x ) { cin >> x; } );
    // Mean
    cout << round ( 100.00 * accumulate ( X.begin() , X.end() , 0 ) / X.size() ) / 100 << endl;
    // Median
    sort ( X.begin() , X.end() );
    if ( X.size() % 2 )
        cout << X[ X.size() / 2 ] << endl;
    else
        cout << ( X[ X.size() / 2 ] + X[ X.size() / 2 - 1]) / 2.0 << endl;
    // Mode
    map <int , int> mp;
    for (auto x: X)
    {
        mp [ x ] = (mp [ x ] > 0 ? mp [ x ] + 1 : 1);
    }
    cout << max_element ( mp.begin() , mp.end() , [] (const pair <int , int> &a, const pair <int , int> &b) { return ( a.second < b.second ); })->first << endl;
    return 0;
}

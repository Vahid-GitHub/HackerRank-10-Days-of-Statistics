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
    int n ;
    cin >> n ;
    vector < float > X ( n ) , Xu ( n ) ;
    vector < float > Y ( n ) , Yu ( n ) ;
    for_each ( X.begin() , X.end() , [] ( float &x ) { cin >> x ; } ) ;
    for_each ( Y.begin() , Y.end() , [] ( float &y ) { cin >> y ; } ) ;
    copy ( X.begin() , X.end() , Xu.begin() );
    copy ( Y.begin() , Y.end() , Yu.begin() );
    auto lastIt = unique ( Xu.begin() , Xu.end() ) ;
    Xu.erase ( lastIt , Xu.end() ) ;
    lastIt = unique ( Yu.begin() , Yu.end() ) ;
    Yu.erase ( lastIt , Yu.end() ) ;
    sort ( Xu.begin() , Xu.end() ) ;
    sort ( Yu.begin() , Yu.end() ) ;
    map < float , int > Xmap , Ymap;
    {
        int i = 1 ;
        for_each( Xu.begin() , Xu.end() , [&Xmap, &i] ( float &x ) { Xmap[x] = i++; } ) ;
        i = 1 ;
        for_each( Yu.begin() , Yu.end() , [&Ymap, &i] ( float &y ) { Ymap[y] = i++; } ) ;
    }
    vector < float > D ( Y ) ;
    transform ( X.begin() , X.end() , Y.begin() , D.begin() , [&Xmap, &Ymap] ( float &x , float &y ) { return ( ( Xmap[x] - Ymap[y] ) * ( Xmap[x] - Ymap[y] ) ) ; } ) ;
    cout << (float) round ( ( 1.0 - 6.0 * accumulate( D.begin() , D.end() , 0 ) / n / ( n * n - 1 ) ) * 1000 ) / 1000 << endl ;
    return 0;
}

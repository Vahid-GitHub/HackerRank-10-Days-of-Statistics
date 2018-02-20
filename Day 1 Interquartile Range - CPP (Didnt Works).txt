#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <iomanip>
using namespace std;

pair < int , int > Xi ( const map < int , int > mp, int i )
{
    auto k = mp.begin();
    int j = k->second;
    while ( j <= i )
    {
        k++;
        j = j + k->second ;
    }
    return ( *k ) ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector < int > X ( N ) ;
    vector< int > F ( N ) ;
    map < int , int > XF;
    // Reading input
    for_each ( X.begin() , X.end() , [] (int &x) { cin >> x ; } ) ;
    for_each ( F.begin() , F.end() , [] (int &f) { cin >> f ; } ) ;
    for ( int i = 0 ;
            i < N ;
            XF.insert ( pair < int , int > ( X[i] , F[i] ) ) ,
            i++
            ) ;
    long L = accumulate ( XF.begin() , XF.end() , 0 ,
                             [] ( int val , const map < int , int >::value_type &p) { return ( val + p.second ) ; }
                             ) ;
    float Q1 = 0.5 * ( Xi ( XF , ( L - 2 ) / 4 ).first + Xi ( XF , L / 4 ).first );
    float Q3 = 0.5 * ( Xi ( XF , ( 3 * L - 1 ) / 4 ).first + Xi ( XF , 3 * L / 4 ).first ) ;
    cout << setprecision(1) << fixed << Q3 - Q1 << endl;
    return 0;
}
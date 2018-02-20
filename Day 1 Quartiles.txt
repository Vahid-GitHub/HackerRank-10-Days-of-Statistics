#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector <int> X ( N );
    // Reading input
    for_each ( X.begin() , X.end() , [] ( int &x ) { cin >> x; } );
    // Medians
    sort ( X.begin() , X.end() );
    cout << 0.5 * ( X [ floor ( X.size() / 4 ) ] + X [ floor ( ( X.size() - 2 ) / 4 ) ] )  << endl;
    cout << 0.5 * ( X [ floor ( X.size() / 2 ) ] + X [ floor ( ( X.size() - 1 ) / 2 ) ] )  << endl;
    cout << 0.5 * ( X [ floor ( 3 * X.size() / 4 ) ] + X [ floor ( ( 3 * X.size() - 1 ) / 4 ) ] )  << endl;
    return 0;
}

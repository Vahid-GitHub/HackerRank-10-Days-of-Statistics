#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector <int> X ( N );
    vector <int> W ( N );
    // Reading input
    for_each ( X.begin() , X.end() , [] ( int &x ) { cin >> x; } );
    for_each ( W.begin() , W.end() , [] ( int &w ) { cin >> w; } );
    // Mean
    cout << fixed << setprecision(1) << ((float)inner_product ( X.begin() , X.end() , W.begin() , 0.0 )) / accumulate ( W.begin() , W.end(), 0.0) << endl;
    return 0;
}

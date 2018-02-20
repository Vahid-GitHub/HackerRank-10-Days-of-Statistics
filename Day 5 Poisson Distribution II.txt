#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long factorial ( int k )
{
    long ret = 1;
    while ( k > 1 )
        ret *= k--;
    return ret;
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float lambdaA , lambdaB ;
    cin >> lambdaA >> lambdaB ;
    cout << (float) round ( ( 160 + 40 * ( lambdaA + lambdaA * lambdaA ) ) * 1000 ) / 1000 << endl;
    cout << (float) round ( ( 128 + 40 * ( lambdaB + lambdaB * lambdaB ) ) * 1000 ) / 1000 << endl;
    return 0;
}


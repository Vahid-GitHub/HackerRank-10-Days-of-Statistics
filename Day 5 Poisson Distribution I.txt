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
    float lambda ;
    int k ;
    cin >> lambda >> k ;
    cout << (float) round ( pow ( lambda , k ) * exp ( -lambda ) / factorial ( k ) * 1000) / 1000 << endl;
    return 0;
}


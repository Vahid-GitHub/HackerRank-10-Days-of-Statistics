#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

float phi ( float x , float mu , float sigma )
{
    return ( 0.5 * ( 1 + erf( ( x - mu ) / sigma / sqrt(2) ) ) ) ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float mu , sigma ;
    float x1 , x2 , x3 ;
    cin >> mu >> sigma >> x1 >> x2 >> x3;
    cout << (float) round ( phi ( x1 , mu , sigma ) * 1000 ) / 1000 << endl;
    cout << (float) round ( ( phi ( x3 , mu , sigma ) - phi ( x2 , mu , sigma ) ) * 1000 ) / 1000 << endl;
    return 0;
}


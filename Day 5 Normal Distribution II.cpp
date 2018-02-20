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
    float x1 , x2 ;
    cin >> mu >> sigma >> x1 >> x2;
    cout << (float) round ( ( 1 - phi ( x1 , mu , sigma ) ) * 10000 ) / 100 << endl;
    cout << (float) round ( ( 1 - phi ( x2 , mu , sigma ) ) * 10000 ) / 100 << endl;
    cout << (float) round ( phi ( x2 , mu , sigma ) * 10000 ) / 100 << endl;
    return 0;
}


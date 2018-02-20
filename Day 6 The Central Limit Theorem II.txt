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
    float mu , sigma , x , n ;
    cin >> x >> n >> mu >> sigma ;
    float mu_normal = n * mu , sigma_normal = sqrt( n ) * sigma ;
    cout << (float) round ( phi ( x , mu_normal , sigma_normal ) * 10000 ) / 10000 << endl ;
    return 0;
}


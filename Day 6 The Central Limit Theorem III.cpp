#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float n, mu , sigma , p , z ;
    cin >> n >> mu >> sigma >> p >> z ;
    float mu_normal = mu , sigma_normal = sigma / sqrt( n ) ;
    float A = mu_normal - z * sigma_normal , B = mu_normal + z * sigma_normal ;
    cout << (float) round ( A * 100 ) / 100 << endl ;
    cout << (float) round ( B * 100 ) / 100 << endl ;
    return 0;
}


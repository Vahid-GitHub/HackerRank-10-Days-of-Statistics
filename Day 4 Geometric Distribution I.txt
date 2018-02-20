#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ;
    float a , b ;
    cin >> a >> b >> n;
    float p = a / b;
    cout << (float) round ( pow( 1 - p , n - 1 ) * p * 1000 ) / 1000 << endl;
    return 0;
}

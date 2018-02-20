#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cblas.h>
#include <linear.h>
using namespace std;

void sparse ( double **X , feature_node** &S , int n , int m ) {
    // int n = X.size() , m = X[0].size() ;
    int k = 0 ;
    S = new feature_node* [ n ] ;
    for ( int i = 0 ; i < n ; i++ ) {
        k = 0 ;
        for ( int j = 0 ; j < m ; j++ , k += ( X[i][j] != 0.0 ) ) ;
        S[i] = new feature_node [k + 1];
        k = 0 ;
        for ( int j = 0 ; j < m ; j ++ ) {
            if ( X[i][j] != 0.0 ) {
                S[i][k] = { j+1 , X[i][j] } ;
                // cout << "(" << S[i][k].index << ", " << S[i][k].value << ")\t" ;
                k++ ;
            }
        }
        S[i][k] = { -1 , 1.0 + k } ;
        // cout << "(" << S[i][k].index << ", " << S[i][k].value << ")" << endl ;
    }
}

void print_null(const char *s) {}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Read Train data
    int m , n ;
    cin >> m >> n ;
    double **X , *Y ;
    X = new double* [ n ] ;
    Y = new double [ n ] ;
    for ( int i = 0 ; i < n ; i++ ) {
        X[i] = new double [ m + 1 ] ;
        for ( int j = 0 ; j < m ; j++ )
            cin >> X [ i ] [ j ] ;
        X[i][m] = 1.0 ;
        cin >> Y[i] ;
    }
//    for ( int i = 0 ; i < n ; i++ ) {
//        for ( int j = 0 ; j < m ; j++ )
//            cout << X[i][j] << '\t' ;
//        cout << X[i][m] << '\t' ;
//        cout << Y[i] << endl ;
//    }

    // Read Test data
    int ntest;
    cin >> ntest ;
    double **test ;
    test = new double* [ ntest ] ;
    for ( int i = 0 ; i < ntest ; i++ ) {
        test[ i ] = new double [ m + 1 ] ;
        for ( int j = 0 ; j < m ; j++ )
            cin >> test[ i ] [ j ] ;
        test [ i ] [ m ] = 1.0 ;
    }

    // Convert to Sparce features
    feature_node **sX;
    sparse( X , sX , n , m + 1 ) ;
    feature_node **stest ;
    sparse( test, stest, ntest, m + 1 ) ;

    // Problem statement
    struct problem prob;
    prob.l = n ;
    prob.n = m + 1 ;
    prob.y = Y ;
    prob.x = sX ;
    prob.bias = 1.0 ;
    // Paremeters
    struct parameter param ;
    param.solver_type = L2R_L2LOSS_SVR ;
    param.C = 1.0 ;
    param.p = 0.1 ;
    param.eps = 1e-4 ;
    param.nr_weight = 0 ;
    param.weight = NULL ;
    param.weight_label = NULL ;
    param.init_sol = NULL ;
    const char *error_msg ;
    error_msg = check_parameter(&prob,&param);
	if(error_msg)
	{
		cout << error_msg ;
		exit(1);
	}
	// Calculate best C
//	double best_C, best_rate ;
//	find_parameter_C( &prob, &param, 4, 0.01, 1.0, &best_C, &best_rate ) ;
//	cout << "Best C = " << best_C << ",\t Best rate = " << best_rate << endl ;
	set_print_string_function(&print_null);
	model *mdl = train( &prob, &param ) ;
	// cout << mdl->nr_class << ", " << mdl->nr_feature << endl ;
//	for ( int i = 0 ; i < (mdl->nr_feature + 1) ; i++)
//        cout << mdl->w[i] << '\t' << endl ;
    // feature_node *fn ;
    // fn = new feature_node [4] ;
    // fn[0] = { 1, 0.18 } ;
    // fn[1] = { 2, 0.89 } ;
    // fn[2] = { 3, 1.0 } ;
    // fn[3] = { -1, 0.0 } ;
//    fn[0] = { 1, 0.92 } ;
//    fn[1] = { 2, 0.11 } ;
//    fn[2] = { 3, 1.0 } ;
//    fn[3] = { -1, 0.0 } ;
	for ( int i = 0 ; i < ntest ; i++ )
		cout << predict( mdl , stest[i] ) << endl ;
    return 0;
}


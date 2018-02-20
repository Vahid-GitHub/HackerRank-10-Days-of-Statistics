from sklearn import linear_model as lm

m, n = map ( int , input().strip().split(' ') )
XY = [ [ float(x) for x in input().strip().split(' ') ] for _ in range( n ) ] #[ [ 1 ] * ( m + 1 ) ] * n
X = [ xy[:m] for xy in XY ]
Y = [ xy[m] for xy in XY ]

ntest = int ( input() )
test = [ [ float(t) for t in input().strip().split(' ') ] for _ in range ( ntest ) ]

lr = lm.LinearRegression()
lr.fit( X , Y )
pred = lr.predict ( test )
print ( *[ round( p , 2) for p in pred ] , sep = '\n' )
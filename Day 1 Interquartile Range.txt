import statistics as st

n = int(input())
numbers = list(map(int, input().split()))
frequency = list(map(int, input().split()))

snumbers = []
for i in range(n):
    snumbers = snumbers + ( [numbers[i]] * frequency[i] )
sf = sum(frequency)
snumbers.sort()

if ( n%2 == 0 ):
    Q1 = st.median(snumbers[:sf//2])
    Q3 = st.median(snumbers[sf//2:])
else:
    Q1 = st.median(snumbers[:sf//2])
    Q3 = st.median(snumbers[sf//2+1:])

print(round(float(Q3-Q1), 1))
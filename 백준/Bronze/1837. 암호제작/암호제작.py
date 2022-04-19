import math

n, m = map(int, input().split())
result = 0
for i in range(2, m + 1):
        if math.gcd(n, i) > 1 and math.gcd(n, i) < m:
            result = i
            break

if result == 0:
    print("GOOD")
else :
    print("BAD", end=' ')
    print(result)
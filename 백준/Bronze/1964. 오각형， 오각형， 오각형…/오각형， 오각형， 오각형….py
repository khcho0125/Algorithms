import math
n = int(input())
sum = 0
for i in range (0, n):
    sum += i * 3
print((1 + (n * 4) + sum) % 45678)
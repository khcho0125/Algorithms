N = int(input())
if N % 10 != 0:
    print(-1)
    exit()

A = N // 300
N %= 300
B = N // 60
N %= 60
C = N // 10
print(A, B, C)
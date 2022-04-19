def paelendrom(s):
    k = str(s)
    return k == k[::-1]

def sosu(s):
    for i in range(2, int(s ** 0.5) + 1):
        if s % i == 0:
            return False
    return True


N, M = map(int, input().split())
if M > 10000000:
    M = 10000000
array = [i for i in range(N, M + 1) if paelendrom(i)]
result = [num for num in array if sosu(num)]
for i in result:
    print(i)
print(-1)
N, M = map(int, input().split())

if M < 0 and N < 0:
    print(N * -1 // M * -1)
    print(abs(N % (M * -1)))
elif M < 0 and N >= 0:
    print((N // (M * -1)) * -1)
    print(abs(N % (M * -1)))
else:
    print(N // M)
    print(abs(N % M))
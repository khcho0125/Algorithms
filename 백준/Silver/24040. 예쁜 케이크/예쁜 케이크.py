T = int(input())
for i in range(T):
    N = int(input())
    if N % 3 == 2 or N % 9 == 0:
        print("TAK")
    else:
        print("NIE")
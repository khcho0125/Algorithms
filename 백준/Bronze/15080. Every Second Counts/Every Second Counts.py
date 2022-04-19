H, M, S = map(int, input().split(":"))
H2, M2, S2 = map(int, input().split(":"))
M += H * 60
M2 += H2 * 60
S += M * 60
S2 += M2 * 60
if S > S2:
    S2 += 86400
print(S2 - S)
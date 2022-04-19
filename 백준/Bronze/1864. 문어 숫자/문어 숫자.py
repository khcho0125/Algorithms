s = str(input())
while s != '#':
    n = 0
    sum = 0
    for i in range(1, len(s) + 1):
        if s[-i] == '-':
            n = 0
        elif s[-i] == '\\':
            n = 1
        elif s[-i] == '(':
            n = 2
        elif s[-i] == '@':
            n = 3
        elif s[-i] == '?':
            n = 4
        elif s[-i] == '>':
            n = 5
        elif s[-i] == '&':
            n = 6
        elif s[-i] == '%':
            n = 7
        elif s[-i] == '/':
            n = -1
        
        if i == 1:
            sum += n
        else :
            sum += n * (8 ** (i - 1))
    
    print(int(sum))
    s = str(input())
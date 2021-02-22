T = int(input())
for i in range(T):
    n1 = int(input())
    cnt = 0
    while True:
        cnt += 1
        n2 = n1 + int(str(n1)[::-1])
        if str(n2) == str(n2)[::-1]:
            break
        else:
            n1 = int(n2)
    print(cnt,n2)
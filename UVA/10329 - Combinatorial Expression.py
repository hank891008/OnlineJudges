import math 
try:
    while True:
        n,m = map(int,input().split())
        n1=1
        n2=1
        for i in range (0,n):
        	a,b = map(int,input().split())
        	n1 *= math.comb(a,b)
        for i in range (0,m):
        	a,b = map(int,input().split())
        	n2 *= math.comb(a,b)
        ans = n1//n2
        if(n1%n2!=0):
        	print(0)
        
        elif(len(str(ans))>100):
        	print(-1)
        else:
        	print(ans)
except EOFError:
    pass
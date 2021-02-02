arr =[0,1,3]
for i in range(3,2001):
	arr.append(3*arr[i-1]-arr[i-2])
try:
    while True:
        s = int(input())
        if s==0:
        	break
        print(arr[s])
except EOFError:
    pass
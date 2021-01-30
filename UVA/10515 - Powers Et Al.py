while 1:
	a,b=map(int,input().split())
	if a==0&b==0:
		break
	print(pow(a,b, 10))
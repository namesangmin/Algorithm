lst = []
s = 0
for i in range(int(input())):
    n = list(input().split())
    if n[0]=='push':lst.append(n[1]);s+=1
    elif n[0]=='pop':
        if lst:print(lst.pop());s-=1
        else:print(-1)
    elif n[0]=='size':print(s)
    elif n[0]=='empty':print(1 if s==0 else 0)
    elif n[0]=='top':print(lst[-1] if s!=0 else -1)
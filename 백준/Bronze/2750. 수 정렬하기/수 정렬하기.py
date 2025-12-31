N = int(input())
a = []
for i in range(N):
    a.append(int(input()))
a.sort()
for i in range(N):
    print(f"{a[i]}")
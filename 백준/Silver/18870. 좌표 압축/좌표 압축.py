N = int(input())  
value = input().split() 
values = list(map(int, value))  
sorted_values = sorted(values)
idxList = {}
idx1 = 0
for value in sorted_values:
    if value not in idxList:
        idxList[value] = idx1
        idx1 += 1
result = [idxList[value] for value in values]
print(' '.join(map(str, result)))

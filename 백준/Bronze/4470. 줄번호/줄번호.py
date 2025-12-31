N = int(input())
input_list = []
for i in range(N):
    input_string = input()
    input_list.append(input_string)
for i in range(N):
    print(f"{i+1}. {input_list[i]}") 
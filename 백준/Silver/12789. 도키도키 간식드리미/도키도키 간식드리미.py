import sys

n = int(sys.stdin.readline())
wait = list(map(int, sys.stdin.readline().split()))
target = 1 # 찾아야 하는 간식 받을 사람
tmp = []
while target != n: # 마지막 대기자를 찾을 때 까지
	if wait and wait[0] == target: # wait 큐의 처음이 간식 받을 사람일 때
		wait.pop(0) # 간식받을 사람 pop
		target += 1 # 다음 대기자로 변경
	elif tmp and tmp[-1] == target: # tmp 스택의 마지막이 간식 받을 사람일 때
		tmp.pop() # 간식받을 사람 pop
		target += 1 # 다음 대기자로 변경
	else:
		tmp.append(wait.pop(0)) # wait 큐의 처음과 tmp 스택의 마지막 사람도 간식 받을 사람이 아닐 때
		if len(tmp) > 1 and tmp[-1] > tmp[-2]: # tmp에 2명 이상의 대기자가 있고 tmp의 마지막 원소가 그 전 원소보다 클 경우
			print("Sad") # 에러 처리
			sys.exit() # 프로그램 종료
if (len(wait) == 1 and len(tmp) == 0 and target == wait[0]) or (len(wait) == 0 and len(tmp) == 1 and target == tmp[0]) : # 두 대기줄 중 하나만 하나의 원소가 남아있고 그 마지막 원소가 target과 일치할 경우
	print("Nice")
else:
	print("Sad")
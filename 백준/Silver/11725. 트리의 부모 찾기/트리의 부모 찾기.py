# import queue

# queue = queue.Queue()
# N = int(input())
# arr = [[] for _ in range(N+1)]
# for i in range(N-1):
#     a,b = map(int,input().split())
#     arr[a].append(b)
#     arr[b].append(a)
    
# queue.put(1)    #루트인 1번을 시작점으로 넣는다.
# while queue is not None::
#     #큐 탑 ; 큐 팝 
    
#     #for( arr[큐의 최상위 숫자] 가 연결된 애들만큼)
#         #parent[연결된 애들 한명]=큐의 최상위 숫자
#         # 큐.put(연겨된 애들 한명)

    
# for i in range(2,N+1):
#    print(arr[i])
from collections import deque

N = int(input())
arr = [[] for _ in range(N+1)]
parent = [0] * (N + 1)  # 부모 노드 정보를 저장할 리스트

# 트리 구성 정보 입력 받기
for i in range(N-1):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

queue = deque([1])  # 루트 노드를 큐에 추가
parent[1] = -1  # 루트 노드의 부모는 없음(-1 또는 None으로 설정 가능)

# BFS 실행
while queue:
    node = queue.popleft()  # 현재 노드

    for neighbor in arr[node]:  # 현재 노드에 연결된 노드들 확인
        if parent[neighbor] == 0:  # 아직 방문하지 않은 노드인 경우
            parent[neighbor] = node  # 부모 노드 설정
            queue.append(neighbor)  # 큐에 추가

# 결과 출력
for i in range(2, N+1):
    print(parent[i])

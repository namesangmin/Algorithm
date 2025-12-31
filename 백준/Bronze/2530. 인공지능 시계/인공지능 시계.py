# 현재 시각을 시, 분, 초로 입력 받음
A, B, C = map(int, input().split())
# 요리에 필요한 시간을 초 단위로 입력 받음
D = int(input())

# 현재 시각을 초 단위로 전환
current_seconds = A * 3600 + B * 60 + C
# 요리 시간을 더해 최종 시각의 초 단위 총합을 계산
total_seconds = current_seconds + D

# 최종 시각을 시, 분, 초로 변환
final_hour = (total_seconds // 3600) % 24
final_minute = (total_seconds % 3600) // 60
final_second = total_seconds % 60

# 최종 시각 출력
print(final_hour, final_minute, final_second)

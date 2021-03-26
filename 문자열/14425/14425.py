import sys
n,m= map(int ,sys.stdin.readline().split())
arr=dict()#딕셔러니 선언
cnt=0

for _ in range(n):
    s=sys.stdin.readline() #각 값 모두 넣어줌
    arr[s]=True
    
for _ in range(m):
    m=sys.stdin.readline()
    
    if m in arr.keys():#키값으로 가지고 있는 지 체크 O(1)걸린다.
        cnt+=1
print(cnt)
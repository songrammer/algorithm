N=int(input())
K=int(input())
arr=list(map(int, input().split()))

arr.sort()
dist=[0 for i in range(N-1)]

ans=0

for i  in range(N-1):
  dist[i]=abs(arr[i]-arr[i+1])
  ans+=abs(arr[i]-arr[i+1]) #전체거리


dist.sort(reverse=True)
index=0
K-=1
# K-1만큼 반복해서 빼줘야 K개의 묶음인 수신 가능 영역이 구해진다.

while K:
  if index == N-1:
    break
    # K가 >N으로 주어질 경우도 있으니 예외처리
  ans-=dist[index]
  index+=1
  K-=1

print(ans)
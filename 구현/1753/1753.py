from  heapq import heappush,heappop
[v,e]=list(map(int,input().split()))
start=int(input())

INF=1000000000
heap=[] #우선순위 힙구하기
d=[INF]*(v+1)


adj=[[] for _ in range(v)]

def dij(cur):
  d[cur]=0
  heappush(heap,[0,cur])
  while heap:
    value,x=heappop(heap) #힙에서 가장 작은 숫자 빼기
    for  x_value,y in adj[x]:
      y_value= x_value+value
      if y_value<d[y]:
        d[y]=y_value
        heappush(heap,[y_value,y])
        
for _ in range(e):
    [x,y,z]=list(map(int,input().split()))
    adj[x-1].append([z,y-1])#인접리스트 인데, 우선순위 큐를 사용하게 때문에 가중치를 앞으로 둬야한다.
    
    
dij(start-1)


for i in range(v):
    if(d[i]==INF):
      print("INF")
    else :
      print(d[i])

    
   
    
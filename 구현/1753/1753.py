[v,e]=list(map(int,input().split()))
start=int(input())

INF=1000000000

d=[INF]*(v+5)
visited=[0]*(v+5)

adj=[[INF]*(v)for _ in range(v)]

def getSmallindex():
  min_value=INF
  index=0
  for i in range(v):
    if(d[i]<min_value and visited[i]==0):
      min_value=d[i]
      index=i
  return index

def dij(cur):
  for i in range(v):
    d[i]=adj[cur][i] #값 집어넣기 
  visited[cur]=1
  for i in range(v-2):
    now=getSmallindex()
    visited[now]=1
    for j in range(v):
      if(visited[j]==0):
        if(d[now]+adj[now][j]<d[j]):
          d[j]=d[now]+adj[now][j]



for _ in range(e):
    [x,y,z]=list(map(int,input().split()))
    adj[x-1][y-1]=min(adj[x-1][y-1],z)
   

for i in range(v):
    adj[i][i]=0 #자기자신으로 돌아오는건 0
    

    
dij(start-1)


for i in range(v):
    if(d[i]==INF):
      print("INF")
    else :
      print(d[i])

    
   
    
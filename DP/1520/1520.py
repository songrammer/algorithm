import sys

dx=[0,0,-1,1]
dy=[-1,1,0,0]

N,M=map(int,input().split())

p=[]

visited=[[-1]* M for _ in range(N)]

for _ in range(N):
  temp=list(map(int ,sys.stdin.readline().rsplit()))
  p.append(temp)

def check_num(a,b):
  if( 0<= a <N and 0<= b <M):
    return True
  else :
    return False

def DFS(x,y):
  if(x==0 and y==0):
    return 1  #돌아왔으면 
  if visited[x][y]==-1:
    visited[x][y]=0 #방문 안했으며 탐색을 위해 0으로 초기화
    for z in range(4):
      nx=dx[z]+x
      ny=dy[z]+y
      if(check_num(nx,ny) and p[nx][ny]>p[x][y]):#탐색ㅇ이 가능하면
        visited[x][y]+=DFS(nx,ny)#탐색하고 결과값 저장

  return visited[x][y]

print(DFS(N-1,M-1))#거꾸로 시작한다.

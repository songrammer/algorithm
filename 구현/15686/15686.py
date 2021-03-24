import sys
from collections import deque
n,m= list(map(int, sys.stdin.readline().split()))
arr = [list(map(int, input().split())) for _ in range(n)] #입력 받기



dx=[0,0,1,-1]
dy=[-1,1,0,0]

def BFS(x,y):

    visited =[[-1]*n for _ in range(n)]
    queue=deque()
    visited[x][y]=0
    queue=deque()
    queue.append((x,y))
    while queue:
        x,y=queue.popleft()
        print("cur",x,y)
        if(arr[x][y]==2):
            return visited[x][y]
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            
            if(nx >=0 and nx <n and ny >=0 and ny <n):
                # print("new",nx,ny)
                if(visited[nx][ny]==-1 and arr[nx][ny]!=1):
                    visited[nx][ny]=visited[x][y]+1
                    queue.append((nx,ny))
                    
    


ans=0


for i in range(n):
    for j in range(n):
        if(arr[i][j]==1):
            print("go",i,j ,"pic",arr[i][j])
            result=BFS(i,j)
            print("return",result)
            ans+=result
            


            
print(ans)
        
      
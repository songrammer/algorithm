import sys
N,M=map(int,input().split())

p=[]
for _ in range(N):
  temp=list(map(int ,sys.stdin.readline().rsplit()))
  p.append(temp)

queue=[[0,0]];

# x,y,z=queue[0]
# print(x,y,z)
def check_num(a,b):
  if( 0<= a <N and 0<= b <M):
    return True
  else :
    return False


dx=[0,0,-1,1]
dy=[-1,1,0,0]
for i in range(N):
  for j in range(M):
    # print("cur",i,j)
    new_queue=[]
    for k in range(len(queue)):
      not_include=True
      x,y=queue[k]
      # print("k:",x,y)
      for z in range(4):
        nx=dx[z]+i
        ny=dy[z]+j
        if(check_num(nx,ny)):
          # print("nx :",nx," ny:",ny)
          if(x==i and y==j):
              if(p[nx][ny]<p[x][y]):
                not_include=False
                # print("pass1",nx,ny)
                new_queue.append([nx,ny])
          elif(nx==x and ny==y):
              if(p[i][j]<p[x][y]):
                not_include=False
                # print("pass2",i,j)
                new_queue.append([i,j])
      if(not_include):
        # print("pass3",x,y)
        new_queue.append([x,y])
    queue=[]
    queue=new_queue
    # print("arr")
    # print(queue)
    # print("done")

ans=0
for k in range(len(queue)):
  if(queue[k][0]==N-1 and queue[k][1]==M-1):
    ans+=1
print(ans)






 
             
     

            


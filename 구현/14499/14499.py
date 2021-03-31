import sys

cur=[3,4,2,5,1,6] #동,서,북,남 ,위,아래
dx=[0,0,-1,1]
dy=[1,-1,0,0]
value=[0]*7

def move_dic(go,vi_go): #주사위 위치 이동
    temp=[0]*6
    for i in range(6):
        temp[i]=cur[i]
    temp[5]=cur[go]
    temp[4]=cur[vi_go]
    temp[go]=cur[4]
    temp[vi_go]=cur[5]
    return temp
    
def find_dic(go): #상대 위치 구하기(동=>서, 남=>북)
    if(go==0):
        return 1
    elif(go==1):
        return 0
    elif(go==2):
        return 3
    else :
        return 2
    
def check_range(x,y):
    if(x>=0 and x <n and y >=0 and y <m): #범위 이탈 여부 체크
        return False
    else :
        return True
        

[n,m,x,y,k]=list(map(int,sys.stdin.readline().strip().split()))

arr=[list(map(int, input().split())) for _ in range(n)]

dir_go=list(map(int,sys.stdin.readline().strip().split()))

 
for i in range(k):
  
    nx=x+dx[dir_go[i]-1]
    ny=y+dy[dir_go[i]-1]
    
    if(check_range(nx,ny)):
        continue
 
    now_go=dir_go[i]-1
    vice_go=find_dic(now_go)
   
    cur=move_dic(now_go,vice_go)
  
    print(value[cur[4]]) #윗면 출력
    
    temp=value[cur[5]]
    value[cur[5]]=arr[nx][ny]
    arr[nx][ny]=temp 
    #주사위와 판 값 교환
    
    x=nx
    y=ny
    
    
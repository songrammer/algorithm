import sys
t =int(input())
MAX=1005
vistied=[0]*(MAX)
l=[-1]*(MAX)
f=[-1]*(MAX)

def go(cur,adj):
    vistied[cur]=1
    for i  in range(len(adj[cur])):
        next_cur= adj[cur][i]
        if(f[next_cur]==-1 or vistied[f[next_cur]]==0 and go(f[next_cur],adj)):
            #옮 길수있는 경우 or 아예 매칭이 안된 경우를 탐색하면서
            l[cur]=next_cur
            f[next_cur]=cur
            return True
    return False

while t:
    ans=0
    
    [n,m]=list(map(int,input().split()))
    adj=[[]for _ in range(m+5)] #인접리스트
    l=[-1]*(m+5) #사람
    f=[-1]*(n+5) #책 수
  
    start=1
    end=m+1
    
    for i in range(start,end):
        [a,b]=list(map(int,input().split())) #인접리스트 입력 받음
        for j in range(a,b+1):
          adj[i].append(j)

    for i in range(start,end):#하나씩 탐색
        if(l[i]==-1):
            vistied=[0]*(m+5)
            if(go(i,adj)):
                ans+=1
                
    print(ans)
    
    t-=1
    

    
    
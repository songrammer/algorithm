[n,m]=list(map(int,input().split()))
left=[-1]*(n+1)
right=[-1]*(m+1)

abj=[[] for _ in range(n+5)]
ans=0
visited=[0]*(n+5)

def dfs(cur):
  visited[cur]=True
  for i in range(len(abj[cur])):
    next_x=abj[cur][i]
    if(right[next_x]==-1 or visited[right[next_x]]==0 and dfs(right[next_x])):
      right[next_x]=cur
      left[cur]=next_x
      return True
  return False

for i in range(1,n+1):
  arr=list(map(int,input().split()))
  for j in range(1,len(arr)):
    abj[i].append(arr[j])

ans=0

for i in range(1,n+1):
  if(left[i]==-1):
    visited=[0]*(n+5)
    if(dfs(i)):
      ans+=1
print(ans)


   
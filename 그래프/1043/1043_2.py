import sys
n,m =map(int,input().split())
ans=m
true_p=list(map(int,input().split()))[1:]
partyArr=[]
parent=[0]*(n+5)

def find(x):
  if(parent[x]==x): 
    return x
  else :
    x = find(parent[x])
    return x

def union(x,y):
  x=find(x)
  y=find(y)
  if(x<y):
    parent[y]=x
  else :
    parent[x]=y

for _ in range(m):
  party=list(map(int,sys.stdin.readline().rsplit()))[1:]
  partyArr.append(party)

for i in range(n):
  parent[i+1]=i+1


for i in range(len(partyArr)): #같은 파티 끼리 union-find
  for j in range(len(partyArr[i])-1):
    x=partyArr[i][j]
    y=partyArr[i][j+1]
    union(x,y)

cnt=0
for x in partyArr:
  check=False
  for y in x:
    if(check):
      break
    for i in range(len(true_p)):
      if(find(true_p[i])==find(y)): #부모가 같은 지 비교
        check=True
        break
  if check:
    cnt+=1

print(m-cnt)
      
    
     


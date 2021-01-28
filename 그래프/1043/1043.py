import sys
n,m =map(int,input().split())
ans=m
true_p=list(map(int,input().split()))[1:]
partyArr=[]

for _ in range(m):
  party=list(map(int,sys.stdin.readline().rsplit()))[1:]
  party.sort()
  partyArr.append(party)

check=[0]*(n+1)

cnt =set()
while(len(true_p)>0):
    true_man=true_p.pop(0)
    check[true_man]=1
    for i  in range(len(partyArr)):
        result =False
        if(true_man in partyArr[i]):
            result=True
            cnt.add(i)
        if(result):
            for y in partyArr[i]:
                if check[y]==0:
                    check[y]=1
                    true_p.append(y)

print(ans-len(cnt))
               
        
                
       
   
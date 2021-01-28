import sys
n,m =map(int,input().split())
ans=m
true_p=list(map(int,input().split()))[1:]
partyArr=[]

for _ in range(m):
  party=list(map(int,sys.stdin.readline().rsplit()))[1:]
  partyArr.append(party)

check=[0]*(n+1)

cnt =set() #파티의 반복 카운팅을 막기 위해 set

while(len(true_p)>0):
    true_man=true_p.pop(0) #한 명씩 제외해주며 파티에 포함되는지 찾는다.
    check[true_man]=1

    for i  in range(len(partyArr)):
        result =False
        if(true_man in partyArr[i]):
            result=True
            cnt.add(i)#진실을 말하는 사람이 포함된 파티 추가

        if(result):
            for y in partyArr[i]: #진실을 말하는 사람이 포함된 파티에 있는 사람을 진실을 말하는 사람으로 판단 하고 queue에 추가
                if check[y]==0:
                    check[y]=1
                    true_p.append(y)

print(ans-len(cnt))
               
        
                
       
   
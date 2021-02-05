N = int(input())
ki =[[0]* N for _ in range(N)]
cnt =[[0]* 2 for _ in range(N)]
arr=list(map(int,input().split()))

ans =0
      
for i in range(N):
    maxHeight=-2000000000000
    for j in range(i+1,N):
        ki=((arr[j]-arr[i])/(j-i))
        if(maxHeight<ki): #보이는 지확인
            cnt[i][1]+=1 #오른쪽으로 보이는 빌딩 수를 증가 시켜줌
            cnt[j][0]+=1 #왼쪽으로 보이는  빌딩 수를 증가 시켜줌
        maxHeight=max(ki,maxHeight) #기울기 최댓값 저장

ans=0
# print(cnt)
for i in range(N): #좌 우로 보이는 빌딩수 카운팅
    ans=max(ans,cnt[i][0]+cnt[i][1])
    
print(ans)
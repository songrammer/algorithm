
T=int(input())

ans=2e9
while T:
    k=int(input())
    dp=[[0]* k for _ in range(k)]
    ca=[[2e9]* k for _ in range(k)] #비용의 최대값이니까 초기화
    arr= list(map(int,input().split()))
    
    for i  in range(k):
        dp[i][i]=arr[i]
        ca[i][i]=0 #아무것도 안 더했을때,상황을 고려하여  초기화 0으로

    for i in range(1,k):
      for j in range(i,k):
        x=j-i
        for m in range(x,j):
          dp[x][j]=dp[x][m]+dp[m+1][j] #현재 드는 비용 저장
          temp_sum=dp[x][j]+ca[x][m]+ca[m+1][j]#현재 드는 비용 과이전 비용들까지의 합 구하기

          ca[x][j]=min(temp_sum,ca[x][j])
                  
    print(ca[0][k-1])
   
    T-=1


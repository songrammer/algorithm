[N,K]=list(map(int ,input().split()))

dp=[[0]*(K+1) for _ in range(N+1)]

arr=[]

for _ in range(N):
    [w,v]=list(map(int ,input().split()))
    arr.append([w,v])

    
arr.sort(key=lambda x:(x[1],-x[0]),reverse=True)
    
for i in range(1,N+1):
        weight,value=arr[i-1][0], arr[i-1][1]
        for j in range(1,K+1):
            if(j<weight):
                dp[i][j]=dp[i-1][j]
             
            else :
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight]+value)
                    
           
print(dp[N][K])
                
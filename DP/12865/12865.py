[N,K]=list(map(int ,input().split()))

dp=[[0]*(K+1) for _ in range(N)]

arr=[]

for _ in range(N):
    [w,v]=list(map(int ,input().split()))
    arr.append([w,v])

    
arr.sort(key=lambda x:(x[1],-x[0]),reverse=True)
    
for i in range(0,N):
        weight,value=arr[i][0], arr[i][1]
        for j in range(K+1):
            if(j<weight):
                continue
            if(i==0):
                dp[i][j]=value
            else :
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight]+value)
                    
           
         
print(dp[N-1][K])
                

            
            
        
    
        
        
        
      
    
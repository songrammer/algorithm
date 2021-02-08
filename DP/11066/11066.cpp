
T=int(input())

ans=2e9
while T:
    k=int(input())
    dp=[[2e9]* k for _ in range(k)]
    arr= list(map(int,input().split()))
    
    for i  in range(k):
        dp[i][i]=arr[i]

    for i in range(1,k):
      for j in range(i,k):
        x=j-i
        for m in range(x,j):
          print(x,j," : (",x," ,",m,")+ (",m+1,",",j," )")
          dp[x][j]=min(dp[x][j],dp[x][m]+dp[m+1][j])
        
         
        print("result",dp[x][j])
    
    for i in range(1,k):
      for j in range(i,k):
        x=j-i
        for m in range(x,j):
          print(x,j," : (",x," ,",m,")+ (",m+1,",",j," )")
          dp[x][j]=min(dp[x][j],dp[x][m]+dp[m+1][j])
         
        print("result",dp[x][j])
        
                
    for i in range(k):
      for j in range(k):
        print(dp[i][j],end=" ")
      print()
   
    
    
    T-=1


N = int(input())
cnt =[[0]* 2 for _ in range(N)]
arr=list(map(int,input().split()))


for i in range(N-1):
    maxValue=0
    for x in range(N-i-1):
        j=x+i+1
        # print (i,x)
        # print(arr[i],arr[j])
        if(arr[i]<=arr[j]):
            cnt[j][0]=max((j-i),cnt[j][0])
            cnt[i][1]=max((j-i),cnt[i][1])
            break
        if(arr[i]>arr[j]):
            if(arr[j]>maxValue):
                cnt[j][0]=max((j-i),cnt[j][0])
                cnt[i][1]=max((j-i),cnt[i][1])
            else :
                cnt[i][1]=max((j-i),cnt[i][1])
        maxValue=max(maxValue,arr[j])
         
    # print(cnt)
                
ans =0
for i in range(N):
    ans=max(ans,cnt[i][0]+cnt[i][1])
print(ans)
        
                

    
    
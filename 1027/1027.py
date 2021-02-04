N = int(input())
cnt =[[0]* 2 for _ in range(N)]
arr=list(map(int,input().split()))

start=0;
end=0
while end<N:
    # print(arr[start],arr[end])
    if(start==end):
        end +=1
        continue
    if(arr[start]<=arr[end]):
        cnt[end][0]=max(cnt[end][0],end-start)
        start+=1
    else: 
        cnt[start][1]=max(cnt[start][1],end-start)
        end +=1
    # print(cnt)

ans =0
for i in range(N):
    ans=max(ans,cnt[i][0]+cnt[i][1])
print(ans)
        
        
    
    
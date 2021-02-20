n,m= map(int,input().split())
arr =list(map(int,input().split()))

start=0
end=0
ans=0
sum_=0

while(1):
  if(sum_>=m): #크거나하거나 같을시에 
    sum_-=arr[start] #빼고
    start+=1 #start을 한 칸 옮김
  elif(end==n): #end가 배열을 넘아갈시에 종료
    break
  elif(sum_<m): #숫자가 작을시에
    sum_+=arr[end] #더하고
    end+=1 #start을 한 칸 옮김
  if(sum_==m): #값을 변화한 후에 같으면 카운팅
    ans+=1


print(ans)
  

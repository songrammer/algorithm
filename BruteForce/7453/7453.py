n=int(input())
arr_a=[]
arr_b=[]
arr_c=[]
arr_d=[]
for _ in range(n):
    [a,b,c,d]=list(map(int,input().split()))
    arr_a.append(a)
    arr_b.append(b)
    arr_c.append(c)
    arr_d.append(d)

arr1=[]
for i in range(n): #a와 b의 합 배열을 저장
    for j in range(n):
        sumAB=arr_a[i]+arr_b[j]
        arr1.append(sumAB)

arr2=[]

for i in range(n): #c와 d의 합 배열을 저장
    for j in range(n):
        sumCD=arr_c[i]+arr_d[j]
        arr2.append(sumCD)
arr2.sort() #이분 탐색을 위해 정렬

ans=0
for i in range(len(arr1)): #arr1의 배열을 돌면서
    num=arr1[i]
    start=0
    end=len(arr2)

    while(start<=end): #이분탐색으로 합이 0이 되는 갯수를 찾기
        mid=(start+end)//2
      
        if(arr2[mid]==-num):
            ans+=1
            break
        elif(arr2[mid]<-num):
          start=mid+1
        
        else:
          end=mid-1
            
print(ans)





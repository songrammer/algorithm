t = int(input())
while t :
    result=False
    n = int(input())
    str_arr=[]
    
    while n:
      x=input()
      str_arr.append(x)
      n-=1
      
    str_arr.sort() #오름차순 정렬

    for i in range(len(str_arr)-1):
        if(str_arr[i]==str_arr[i+1][0:len(str_arr[i])]):
         #만일 해당 문자열이 다음 차순 배열에 접두사라면
            result=True
            break
        
    if(result):
        print("NO")
    else:
        print("YES")
       
    t-=1
    
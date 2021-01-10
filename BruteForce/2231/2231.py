
n = input()
ans=0;
def divide(num): #각 자기수의 합 구하기
    result=0;
    while num:
        result = int(result) + int(num%10)
        num = int(num/10)
    return result
  

for i in range(1,1000005): 
   
    if  divide(i)+i == int(n):
        ans=i
        break
   
if ans :
    print(ans)
else:
    print(ans)
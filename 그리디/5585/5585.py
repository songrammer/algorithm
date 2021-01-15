#파이썬 문법 연습
pay=1000-int(input())
ans=0

arr=[500,100,50,10,5,1]

for x in arr:
  ans+=(pay//x)
  pay%=x

print(ans)

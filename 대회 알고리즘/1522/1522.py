strs =input()
a_cnt=0
b_cnt=0
for c in strs:
  if(c=='a'):
    a_cnt+=1
  else :
    b_cnt+=1
    
ans=len(strs)
for index in range(len(strs)-b_cnt+1):
    ans=min(ans,strs[index:index+b_cnt].count('a'))

for index in range(len(strs)-a_cnt+1):
    ans=min(ans,strs[index:index+a_cnt].count('b'))
print(ans)
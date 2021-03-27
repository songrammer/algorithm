import sys
s= sys.stdin.readline().rstrip() #뒤에 공백 문자열 제거

check='abcdefghijklmnopqrstuvwxyz'

dic={}

for i in range(len(s)):
    if s[i] not in dic.keys(): #처음 들어가는 거라면
        
        dic[s[i]]=i
        
        
for i in check:
    if i in s:
        print(dic[i],end=" ")
    else :
        print("-1",end=" ")
        
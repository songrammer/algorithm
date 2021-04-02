import re
N=int(input())



def go(strNum, index,x):
    if index== x:
      reStr=strNum.split() 
      filterStr=''.join(reStr) #최종값에서 공백으로 매워진 경우 숫자 붙임
      arrNum = list(map(int, re.findall("\d+", filterStr)))  #숫자만 분리
      
      cnt=0
      result=arrNum[cnt]
      cnt += 1
      
      for i in range(len(filterStr)):
          if(filterStr[i]=='+'): #모두 돌면서 부호인 경우 계산
            result+=arrNum[cnt]
            cnt+=1
          elif(filterStr[i]=='-'):
             result-=arrNum[cnt]
             cnt += 1
             
      if (result == 0): #0일때 완성된 문자열 출력
          print(strNum)
         
      return
            
    go(strNum +" "+str(index+1),index+1,x)
    go(strNum +"+"+str(index+1),index+1,x)
    go(strNum +"-"+str(index+1),index+1,x)
    
while N:
    x=int(input())
    
    go("1",1,x)
    print()
    
    N-=1
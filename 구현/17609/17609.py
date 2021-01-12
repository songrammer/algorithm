def palindrome(str):
    left=0;
    right=len(str)-1
    skip=True #한번스킵할 수 있는 기회
    result =True
    
    while(left<=right): #왼쪽 스킵
       
        if str[left] == str[right]: #같으면 왼쪽과 오른쪽 양쪽에서 둘다 이동
           
             left=left+1
             right=right-1
             continue
        if skip: 
            left=left+1
            skip=False #한번 스킵할당량 소진
            continue
        else : #문자가 같지 않은 경우이므로 문자열로 분류
            result=False
            break

    
    if(result) : #유사회문이면 검사할 필요없이 종료
        return result 

    left=0;
    right=len(str)-1
    skip=True
    result=True
            
    while(left<right): #오른쪽 스킵
        if str[left] == str[right]:
             left=left+1
             right=right-1
             continue
        if skip:
            right=right-1
            skip=False
            continue
        else :
            result=False
            break
   
    return result
                
def check(str):
    if str == str[::-1]: #회문인지 확인
        return 0
    if palindrome(str):  #회문 유사회문인지 확인
        return 1
    else :
        return 2

t = input()   
for _ in range(int(t)):
    x =input()
    print(check(x))



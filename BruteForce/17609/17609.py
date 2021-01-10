t = input()
arr=[]

def check(str):
    if(str[::-1]==str): #회문인지 확인
        return 0
    else:
        result=False
        for i in range(len(str)): #유사회문 가능한지 확인
            changeStr=str[:i]+str[i+1:len(str)]
            if(changeStr ==changeStr[::-1]):
                result=True
                break;
        if result:
            return 1
        else :
            return 2
    
for _ in range(int(t)):
    x =input()
    print(check(x))



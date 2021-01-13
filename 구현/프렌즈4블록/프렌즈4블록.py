def solution(m, n, board):
    answer = 0
    for i in range(m): #문자열 리스트화
        board[i]=list(board[i])

    while 1: #2×2 의 같은게 안나올때 까지 반복
        arr=[]
        go=False
        for x in range(len(board)-1):
            for y in range(len(board[x])-1):
                ki=board[x][y]
                if(ki !='0'and board[x][y+1]==ki and board[x+1][y]==ki and board[x+1][y+1]==ki):
                    go=True
                    arr.append([x,y]) #2×2 같은거의 시작점 넣기

        if go==False:
            break
                
        for index in range(len(arr)): #같은거 0으로 그림 변환
            x,y=arr[index]
            board[x][y]="0"
            board[x][y+1]="0"
            board[x+1][y]="0" 
            board[x+1][y+1]="0"
        
        while 1 : #밑에 빈 공간이 없을때 까지 옮김

            move=False
            for i in range(m-1):
                for j in range(n):
                    if(board[i][j]!='0'and board[i+1][j]=='0'): #밑에 빈 공간이 있으면 자리바꿈
                        move=True
                        board[i+1][j]=board[i][j]
                        board[i][j]='0'
            if move==False:
                break

    for i in range(m): #최종 카운팅
        for j in range(n):
            if(board[i][j]=='0'):
                answer+=1
    return answer
                      
        
        
                    
        
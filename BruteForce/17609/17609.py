t = input()
def palindrome(left ,right, skip,str):
    # print(str,left,str[left],right,str[right])
    if left>right  :
        return True
    if str[left] == str[right]:
         return palindrome(left+1,right-1,skip,str)
    if skip :
        # print( palindrome(left,right-1,0,str))
        # print( palindrome(left+1,right,0,str))
        return palindrome(left,right-1,0,str)|palindrome(left+1,right,0,str)
    else :
        return False

    
def check(str):
    if str == str[::-1]: 
        return 0
    if palindrome(0,len(str)-1,1,str): 
        return 1
    else :
        return 2
   
    
for _ in range(int(t)):
    x =input()
    print(check(x))



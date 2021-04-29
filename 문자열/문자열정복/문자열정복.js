function solution(s) {
    
    var answer=s.length;
    var start=0
   
    for(var i=1; i<=s.length/2;i++){
        let str=s.slice(0,i);
         var cnt=1;
        var str_temp='';
        
        for(var j=i; j<s.length;j+=i){
            
            if(str===s.slice(j,j+i)){    
                cnt++;
            }else{
                
                if(cnt>1){
                    //끝지점 까지에 공통 문자열 넣기
                    str_temp+=String(cnt);  
                }
                str_temp+=str;
                str=s.slice(j,j+i);
                cnt=1;

            }
            
        }
        
        if(cnt>1){
            //마지막 끝지점 문자열 넣기
           str_temp +=String(cnt);
        }
        str_temp+=str;
        
        answer=Math.min(answer,str_temp.length);
    }
  
    
    return answer;
}
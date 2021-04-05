#include <iostream>
#include <algorithm>
using namespace std;



struct Point{
    int d;
    int w;
    float value;
    
};

bool cmp (const Point &u,const Point &v){
    
    return u.value >v.value;
}
int main() {
    
    int n;
    cin >>n;
    vector <Point> p;
    for (int i=0; i<n;i++){
        int x,y;
        cin >>x >>y;
        p.push_back({x,y,float(y/x)});
        
    }
    
    sort(p.begin(),p.end(),cmp);
    int ans=0;
   
    while(p.size()>0){
        
        ans+=p[0].w;
        
        vector <Point> temp;
      
        
        for(int i=1; i<p.size();i++){
            if(p[i].d>1){
                p[i].d-=1;
                temp.push_back({p[i].d,p[i].w,float(p[i].w/p[i].d)});
            }
        }
       sort(temp.begin(),temp.end(),cmp);
       
       p=temp;
   
        
    }
    
    cout<<ansš
    
  
   
    return 0;
}
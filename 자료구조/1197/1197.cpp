#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10005];

int findParent(int x){//부모를 찾아주는 함수
    
    if(parent[x]==x) return x;
    else return parent[x]=findParent(parent[x]); //이를 통해서 연산 최적화
}


bool sameParent(int x , int y ){ //부모가 같은지 확인하는 함수
    
    x=findParent(x);
    y=findParent(y);
    if(x==y)return true;
    else return false;
} 


void unionFind(int x , int y){
    x=findParent(x);
    y=findParent(y);
    if(x!=y){
        parent[y]=x;
    }
    
}

struct Point{
    int value,x,y;
};

bool cmp(const Point &u,const Point &v){
    
    return u.value<v.value;
    
}

int main() {
    
    int v,e;
    cin >>v >>e;
    vector <Point> node;
    
    for(int i=0; i<e;i++){
        int x, y,z;
        cin >>x >>y>>z;
       node.push_back({z,x,y});
        
    }
   
  sort(node.begin(),node.end(),cmp);
  
  for(int i=1;i<=v;i++){
      parent[i]=i; //부모를 초기 자기 자신과 연결 해줌
  }
  
  int sum=0;
  
   for(int i=0;i< node.size();i++){
       int x=node[i].x;
       int y=node[i].y;
     if(!sameParent(x,y)){
         sum+=node[i].value;
         unionFind(x,y);
     }
  }
  cout<<sum<<'\n';
   

    return 0;
}
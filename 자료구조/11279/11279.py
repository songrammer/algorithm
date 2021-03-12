import heapq
import sys 


heap=[]
n =int(input())

for _ in range(n):
  k=int(sys.stdin.readline())#input 사용시 에러가 나기도 한다. 

  if(k==0):
    if(len(heap)>0):
      min_item=heapq.heappop(heap)
      print(-min_item)

    else:
       print(0)
  else :
    heapq.heappush(heap,-k)

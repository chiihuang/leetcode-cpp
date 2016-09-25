#include <queue>
#include <vector>
#include <iostream>

struct CustomType {
  int val;
};

struct comp{
  bool operator()(CustomType a, CustomType b){
    return a.val > b.val;
  }
};

void print_queue(std::priority_queue<CustomType, std::vector<CustomType>, comp> pq){
  while(!pq.empty()){
    std::cout<< pq.top().val << std::endl;
    pq.pop();
  }
}

int main(){
  std::priority_queue<CustomType, std::vector<CustomType>, comp> pq;
  CustomType c1; c1.val = 10; pq.push(c1);
  CustomType c2; c2.val = 1; pq.push(c2);
  CustomType c3; c3.val = 2; pq.push(c3);
  CustomType c4; c4.val = -3; pq.push(c4);
  CustomType c5; c5.val = 8; pq.push(c5);
  CustomType c6; c6.val = 7; pq.push(c6);
  CustomType c7; c7.val = 2; pq.push(c7);
  print_queue(pq);
}

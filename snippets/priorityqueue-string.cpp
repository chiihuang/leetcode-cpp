#include <queue>
#include <vector>
#include <iostream>
#include <functional>

void print_queue(std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq){
  while(!pq.empty()){
    std::cout<< pq.top() << std::endl;
    pq.pop();
  }
}

int main(){
  std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq;

  pq.push("abcd");
  pq.push("ab");
  pq.push("aa");
  pq.push("z");
  pq.push("");
  pq.push("Asd");
  pq.push("asd");
  print_queue(pq);
}

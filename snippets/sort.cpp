#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

struct cus {
  int val;
};

struct compare{
  bool operator()(cus a, cus b) {
    return a.val < b.val;
  }
} ;

int main(){
  std::vector<cus> v;
  for(int i = 0; i < 10; i++){
    cus c;
    c.val = rand() % 1000;
    v.push_back(c);
  }
  std::sort(v.begin(), v.end(), compare());


  for(auto item : v){
    std::cout<< item.val << " , ";
  }
  std::cout << std::endl;
}
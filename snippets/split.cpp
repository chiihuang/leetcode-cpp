#include <string>
#include <sstream>
#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main(){
  std::string s = "hate, your,,, big, lie,, \nto,us";
  std::vector<std::string> elems = split(s, ',');
  for(auto e : elems){
    std::cout << e << std::endl;
  }
}

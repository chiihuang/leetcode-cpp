#include <vector>
#include <iostream>
using namespace std;

int parent(int i) {
  return (i - 1) / 2;
}

int left(int i) {
  return 2 * i + 1;
}

int right(int i) {
  return 2 * i + 2;
}

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}

void printVec(vector<int> v){
  for (auto i = v.begin(); i != v.end(); ++i)
    cout << *i << ' '; 
}

vector<int> heapSort(vector<int>& nums){
  int len = nums.size();
  for(int i = 0; i < len; i++){
    int pi = parent(i);
    int ci = i;
    while(pi >= 0){
      if(nums[ci] > nums[pi]){
        swap(nums[ci], nums[pi]);
        ci = pi;
        pi = parent(pi);
      } else {
        break;
      }
    }
  }

  for(int i = len - 1; i >= 0; i--){
    swap(nums[0], nums[i]);

    int ci = 0;

    while(true){
      int li = left(ci);
      int ri = right(ci);
      if(li >= i && ri >= i) break;

      if (ri >= i) {
        if (nums[ci] < nums[li]) {
          swap(nums[ci], nums[li]);
          ci = li;
        }
        break;
      } else if (li >= i) {
        if (nums[ci] < nums[ri]) {
          swap(nums[ci], nums[ri]);
          ci = ri;
        }
        break;
      } else {
        if (nums[li] > nums[ri] && nums[ci] < nums[li]) {
          swap(nums[ci], nums[li]);
          ci = li;
        } else if (nums[ci] < nums[ri]){
          swap(nums[ci], nums[ri]);
          ci = ri;
        } else {
          break;
        }
      }
    }
  }
  return nums;
}

int main() {
  vector<int> arr = {1 , 0, 2, 5, 7, 3, 9, 11};
  heapSort(arr);
  printVec(arr);
}


#include <vector>
#include <iostream>

int binary_search(const std::vector<int> & nums, int target){
  int hi = nums.size() - 1;
  int lo = 0;
  int mid = lo;
  while(lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) {
      break;
    } else if (nums[mid] < target) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  if (nums[mid] == target || mid <= 0 || mid >= nums.size() - 1) {
    return mid;
  } else if (nums[mid] < target) {
    lo = mid + 1;
    return 
  } else {
    hi = mid - 1;
  }

  return mid;
}

int main(){

  std::vector<int> arr1 = {0, 1, 2, 3, 10};
  std::cout << "target: " << 4 << " at index: " << binary_search(arr1, 4) << std::endl;
  std::cout << "target: " << -1 << " at index: " << binary_search(arr1, -1) << std::endl;
  std::cout << "target: " << 3 << " at index: " << binary_search(arr1, 3) << std::endl;
  std::cout << "target: " << 10 << " at index: " << binary_search(arr1, 10) << std::endl;
}

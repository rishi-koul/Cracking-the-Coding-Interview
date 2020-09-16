#include <iostream>
using namespace std;

int magicIndexSearch(int arr[11], int start, int end){
  if(end < start)return -1;

  int midIndex = (start+end) / 2;
  int midValue = arr[midIndex];

  if(midValue == midIndex){
    return midIndex;
  }
  
  // Cause the ques states that there can be "dupliactes" in the array binary search cannot work, we need to search both right and left always
  
  // Search left
  int leftIndex = min(midIndex - 1, midValue);
  int left = magicIndexSearch(arr, start, leftIndex);
  if(left >= 0)return left;

  // Search right
  int rightIndex = max(midIndex + 1, midValue);
  int right = magicIndexSearch(arr, rightIndex, end);
  if(right >= 0)return right;

  return -1;
}

int magicIndexSearch(int arr[11]){
  return magicIndexSearch(arr, 0, 10);
}

int main() {
  int arr[11] = {-10, -5, 2, 2, 2, 3, 4, 7, 9 , 12, 13};

  cout<<magicIndexSearch(arr);
}

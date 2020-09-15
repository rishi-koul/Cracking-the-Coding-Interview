#include <iostream>

int possibleWays(int n){
  if(n < 0) return 0;
  else if (n == 0)return 1;

  return possibleWays(n-1) + possibleWays(n - 2) + possibleWays(n - 3);
}
int main() {
  std::cout << possibleWays(4);
}

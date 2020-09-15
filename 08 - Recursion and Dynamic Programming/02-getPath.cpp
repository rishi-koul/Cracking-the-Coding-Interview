#include <iostream>
using namespace std;

bool findPath(int matrix[3][4], int col, int row){
  if(col < 0 || row < 0)return false;
  if(matrix[row][col] == 1)return true;
  if(matrix[row][col] == -1)return false;

  bool left = findPath(matrix, (col - 1), row);
  bool up;
  if(left == false)up = findPath(matrix, col, (row - 1));

  if(left || up) {
  cout<<"Row: "<<row<<endl;
  cout<<"Col: "<<col<<endl;
  cout<<endl;
  }
  return left || up;
}

int main() {
  int matrix[3][4] = { {1, 0, 0, 0},
                      {-1, -1, -1, 0},
                      {0, 0, 0, 0} };
  
  findPath(matrix, 3, 2) == false ? cout << "Not a possible path" : cout << " ";
}

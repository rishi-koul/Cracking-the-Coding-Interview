#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> returnSubsets(vector<int> v, int index){
  vector<vector<int>> allSubsets;
  if(v.size() == index){
    allSubsets = {};
    allSubsets.push_back({});
  }

  else{
    allSubsets = returnSubsets(v, index + 1);
    int item = v[index];
    vector<vector<int>> moreSubsets = {};

    for (auto i = allSubsets.begin(); i != allSubsets.end(); ++i) {
      vector<int> newSubset = {};
      for(auto j = (*i).begin(); j != (*i).end(); ++j){
        newSubset.push_back(*j);
      }
      newSubset.push_back(item);

      moreSubsets.push_back(newSubset);
    }
    for(auto i = moreSubsets.begin(); i != moreSubsets.end(); ++ i){
      allSubsets.push_back(*i);
    }
  }
  return allSubsets;
}

int main() {
  vector<int> v = {7, 5, 8};
  vector<vector<int>> allSubsets = returnSubsets(v, 0);
  for (auto i = allSubsets.begin(); i != allSubsets.end(); ++i) {
    for(auto j = (*i).begin(); j != (*i).end(); ++j){
      cout<<*j;
      }
    cout<<endl;
    }

}

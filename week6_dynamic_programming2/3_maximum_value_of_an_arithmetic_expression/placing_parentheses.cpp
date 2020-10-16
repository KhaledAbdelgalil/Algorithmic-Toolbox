#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;


long long get_maximum_value(const string &expression) {
  //write your code here
  if(expression.size() == 1 )return expression[0] - 48;
  
  vector<int>nums;
  vector<char>operators;
  for(int i = 1; i < expression.size(); i += 2) operators.push_back(expression[i]);
  for(int i = 0; i < expression.size(); i += 2) nums.push_back(expression[i] - 48);
  
  long long MaxVal[nums.size()][nums.size()];
  long long MinVal[nums.size()][nums.size()];
  
  //initialization
  for(int i = 0; i < nums.size(); i++){
      for(int j = 0 ; j < nums.size(); j++){
          if(i == j){
              MaxVal[i][j] = MinVal[i][j] = nums[i];
              continue;
          }
          MaxVal[i][j] = -100000000;
          MinVal[i][j] =  100000000;
      }
  }
  
  //
  for(int L = 1; L < nums.size(); L++){
      for(int i = 0; i < nums.size() - L; i++){
          int j = i + L;
          for(int k = i; k <= j - 1; k++){
              if(operators[k] == '+'){
                  MaxVal[i][j] = max(MaxVal[i][j], MaxVal[i][k] + MaxVal[k+1][j]);
                  MinVal[i][j] = min(MinVal[i][j], MinVal[i][k] + MinVal[k+1][j]);
              }
              else if(operators[k] == '*'){
                  MaxVal[i][j] = max( max(MaxVal[i][j], MaxVal[i][k] * MaxVal[k+1][j]), MinVal[i][k] * MinVal[k+1][j] );
                  MinVal[i][j] = min(min( min(MinVal[i][j], MinVal[i][k] * MinVal[k+1][j] ),MinVal[i][k] * MaxVal[k+1][j] ),MaxVal[i][k] * MinVal[k+1][j]);
              }
              else if(operators[k] == '-'){
                  MaxVal[i][j] = max(MaxVal[i][j],MaxVal[i][k] - MinVal[k+1][j]);
                  MinVal[i][j] = min(MinVal[i][j], MinVal[i][k] - MaxVal[k+1][j]);
              }
          }
      }
  }
  return MaxVal[0][nums.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}

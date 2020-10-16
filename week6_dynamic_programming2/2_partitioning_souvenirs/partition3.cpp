#include <iostream>
#include <vector>
#include <algorithm>
using std::max;
using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  //treat the problem like 2 problems knapsack of size sum/3 and sum*2/3 
  int sum = 0;
  for(int i = 0; i < A.size(); i++)sum += A[i];
  
  if(sum % 3 != 0)return 0;
  
  int W[2] = { sum / 3 , 2 * sum / 3 };
  for(int i = 0; i < 2; i++ ){
      int dp[ A.size() + 1 ][ W[i] + 1] = {0};
      for(int j = 0; j <= A.size() ; j++){
          for(int k = 0; k <= W[i]; k++){
              if(k == 0 || j == 0){// you don't have weight or Souvenirs(base case)
                  dp[ j ][ k ] = 0;
                  continue;
              }
              if(k - A[ j - 1 ] >= 0){
                  dp[ j ][ k ] = std::max(dp[ j - 1 ][ k ], dp[ j - 1 ][ k - A[ j - 1 ]] + A[ j - 1 ]);
              }else{
                  dp[ j ][ k ] = dp[ j - 1 ][ k ];
              }
          }
      }
      if(dp[ A.size() ][ W[i] ] != W[i]) return 0; 
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}

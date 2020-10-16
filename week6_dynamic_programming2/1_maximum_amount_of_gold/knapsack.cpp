#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::max;
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  vector< vector<int> > dp( w.size() + 1, vector<int>( W + 1 ,0));
  
  for(int i = 1;i <= w.size();i++){
      for(int j = 1;j <= W;j++)
      {
          if(j-w[i-1] >= 0)//we can take it 
          {
            dp[i][j] = max(dp[i-1][j-w[i-1]] + w[i-1], dp[i-1][j]);
          }else{
              dp[i][j] = dp[i-1][j];
          }
      }
  }
  return dp[w.size()][W];//considering all golds and whole size of knapsack
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}

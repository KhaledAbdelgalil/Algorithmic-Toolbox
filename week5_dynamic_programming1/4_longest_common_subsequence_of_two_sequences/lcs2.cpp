#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  
  vector< vector<int> > table(a.size()+5,vector<int>(b.size()+5,0));
  
  for(int i=1 ;i <= a.size(); i++){
      for(int j=1 ;j <= b.size(); j++){
        if( a[i-1] == b[j-1] ){
            table[i][j] = 1 + table[i-1][j-1];
        }else{
            table[i][j] = std::max(table[i-1][j], table[i][j-1]);
        }
          
      }
      
  }
  
  return table[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}

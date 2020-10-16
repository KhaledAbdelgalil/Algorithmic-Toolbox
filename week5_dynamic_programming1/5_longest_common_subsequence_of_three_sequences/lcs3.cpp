#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  vector < vector < vector <int> > > table(a.size() + 5, vector < vector <int> >(b.size() + 5 , vector<int> (c.size()+5,0)) );
  
  for(int i=1;i<=a.size();i++){
      for(int j=1;j<=b.size();j++){
          for(int k=1;k<=c.size();k++){
              if(a[i-1] == b[j-1]&&a[i-1] == c[k-1])table[i][j][k]=1 + table[i-1][j-1][k-1];
              else table[i][j][k] = std::max({table[i-1][j][k],table[i][j-1][k],table[i][j][k-1],table[i-1][j-1][k],
                 table[i-1][j][k-1],table[i][j-1][k-1]   
              });
          }
      }
  }
  
  
  return table[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

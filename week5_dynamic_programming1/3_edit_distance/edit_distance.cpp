#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  std::vector< std:: vector<int> >table(str1.size()+5,std::vector<int>(str2.size()+5,0)) ;
  //base cases
  for(int i=0;i<=str1.size();i++)table[i][0]=i;
  for(int i=0;i<=str2.size();i++)table[0][i]=i;
  
  for(int i=1;i<=str1.size();i++){
      for(int j=1;j<=str2.size();j++){
          if(str1[i-1]==str2[j-1]){
              table[i][j]=std::min({table[i-1][j-1],table[i-1][j]+1,table[i][j-1]+1});
          }else{
              table[i][j]=std::min({table[i-1][j-1]+1,table[i-1][j]+1,table[i][j-1]+1});
          }
      }
  }
  return table[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

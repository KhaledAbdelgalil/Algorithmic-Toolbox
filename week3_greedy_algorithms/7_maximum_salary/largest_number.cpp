#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>

using std::vector;
using std::string;


bool cmp(const string &a,const string &b){
  string temp1 = a + b;
  string temp2 = b + a;
  // try a+b then b+a and see which is better
  if(temp1>temp2)return true;
  else return false;
} 
string largest_number(vector<string> f) {
  //write your code here
  std::stringstream ret;
  sort(f.begin(),f.end(),cmp);
  for (size_t i = 0; i < f.size(); i++) {
    ret << f[i];
  }
  string result;
  ret >> result;
  return result;
}
string largest_number_test(vector<string> a){
    
    sort(a.begin(),a.end());
    
    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
       ret << a[i];
    }
    string result;
    ret >> result;
    do{
        string temp;
        std::stringstream ret2;
        for (size_t i = 0; i < a.size(); i++) {
            ret2 << a[i];
        }
        ret2 >> temp;
        if(temp>result)result=temp;
    }while(next_permutation(a.begin(),a.end()));
    
    return result;
}
int main() {
    
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
   std::cout << largest_number(a);
  /*//stress testing
  while(1){
      std::vector<string>a;
      for(int i=0;i<5;i++){
         std::stringstream ss;
         for(int j=0;j<=i;j++){
           int n=rand()%10;
           ss << n;
         }
         a.push_back(ss.str());
      }
      
      for(int i=0;i<a.size();i++)std::cout<<a[i]<<" ";
          std::cout<<std::endl;
      
      if(largest_number_test(a)!=largest_number(a)){
          std::cout<<largest_number_test(a)<<" "<<largest_number(a)<<std::endl;
          break;
      }
      else std::cout<<"ok"<<std::endl;
  }*/
 
}

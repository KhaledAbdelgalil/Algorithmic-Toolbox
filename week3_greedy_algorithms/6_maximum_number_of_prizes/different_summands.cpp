#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  
  //The best solution is to make this sequence 1 + 2 + 3 + 4 + ........  =>(n)*(n+1)/ 2
  
  int f=1;
  while(n>(f)*(f+1) / 2 )f++;
  if(n!=(f)*(f+1) / 2)f--;
  
  vector<int> summands;
  //write your code here
  int sum=0;
  for(int i=0;i<f-1;i++)summands.push_back(i+1),sum+=i+1;
  
  if(n!=sum)
  summands.push_back(n-sum);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

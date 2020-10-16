#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  // write your code here
  for(int i=0;i<weights.size();i++){
      
      if(capacity == 0)return value;
      int index_to_take=-1;
      double value_per_unit=-1;
      for(int j=0;j<weights.size();j++){
          if(weights[j]!=0&&((double)values[j]/weights[j])>value_per_unit){
                        value_per_unit=(double)values[j]/weights[j];
                        index_to_take=j;
          }
      } 
      int a=std::min(weights[index_to_take],capacity);//this is you can take now
      capacity=capacity-a;
      value= value + a * value_per_unit ;
      weights[index_to_take]=weights[index_to_take]-a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

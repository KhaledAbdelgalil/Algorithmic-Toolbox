#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
 vector<int> table(n+1,1000000);
 table[0] = 0;
 table[1] = 0;//no steps to make 1 from 1
 for(int i = 2; i <= n; i++){
     if( i % 3 == 0)table[i]=std::min( table[i], table[i/3] + 1);
     if( i % 2 == 0)table[i]=std::min( table[i], table[i/2] + 1);
     table[i]=std::min( table[i], table[i-1] + 1);
 }
 /*for(int i=0;i<table.size();i++)std::cout<<table[i]<<" ";
 std::cout<<std::endl;
 */
 vector<int>sequence;
 sequence.push_back(n);
 //let's build the sequence
 while(n > 1){
        if(n % 3 == 0 && table[n] == table[ n / 3 ] + 1){
            sequence.push_back( n /3 );
            n/=3;
        }
        else if(n % 2 == 0 && table[n] ==  table[ n / 2 ] + 1){
            sequence.push_back(n/2);
            n/=2;
        }
        else {
            sequence.push_back(n-1);
            n--;
        }
 }
 reverse( sequence.begin() , sequence.end() );
 return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

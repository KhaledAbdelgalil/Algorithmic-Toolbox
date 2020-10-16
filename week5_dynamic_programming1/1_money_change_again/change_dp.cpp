#include <iostream>
#include <vector>

using std::vector;
int coins[3]={1,3,4};
int get_change(int m) {
  //write your code here
    vector<int>table(m+5,10000);
    table[0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++){
            if(i-coins[j]>=0){
                table[i]=std::min(table[i],table[i-coins[j]]+1);
            }
        }
    }
    return table[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

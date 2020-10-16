#include <iostream>

int get_change(int m) {
  //write your code here
  int taken10=0,taken5=0,taken1=0;
  taken10=m/10;
  m=m-(m/10)*10;
  taken5=m/5;
  m=m-(m/5)*5;
  taken1=m;
  return taken10+taken5+taken1;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

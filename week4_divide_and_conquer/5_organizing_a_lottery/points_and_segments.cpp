#include <iostream>
#include <vector>
#include <map>
using std::vector;
using std::map;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size(),0);
  //write your code here
  map < int, int > segements;
  map < int, int > occurrence;
  
  for(int i=0; i < starts.size(); i++){
      segements[ starts[ i ] ] += 1;
      segements[ ends[ i ] ] -= 1;
      occurrence[ ends[i] ] += 1;
  }
  
  for(auto  it = segements.begin() ; it != prev(segements.end(), 1 ); it++){
      next( it ) -> second += it -> second;
  }
  
  for(int i = 0 ; i < points.size() ; i++){
      if(points[i] < segements.begin() -> first || points[i] > prev(segements.end(),1) -> first) continue;
      auto it = prev( segements.upper_bound( points[ i ] ) );
      
      if(it -> first != points[i])cnt[ i ] = it -> second;
      else cnt[ i ] = it -> second + occurrence [ it -> first ];
  }
 
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using std::vector;

struct Segment {
  int start, end;
};

bool cmp(const struct Segment &a,const struct Segment &b){
    return a.end<b.end;
}
vector<int> optimal_points(vector<Segment> &segments) {
  
  sort(segments.begin(),segments.end(),cmp);
  vector<int> points;
  //write your code here
  int lastt=segments[0].end;
  points.push_back(lastt);
  
  for (size_t i = 0; i < segments.size(); ++i) {
        if(lastt<=segments[i].end&&lastt>=segments[i].start)continue;//you can collect this segment by last point no need to take more points
        lastt=segments[i].end;
        points.push_back(lastt);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}

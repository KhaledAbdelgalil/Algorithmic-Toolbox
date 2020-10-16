#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct point{
    double x,y;
};

bool compareX(const point &p1, const point &p2){
    return p1.x < p2.x;
}


bool compareY(const point &p1, const point &p2){
    return p1.y < p2.y;
}

double dist(const point &p1,const point &p2){
    double dist1 = (p1.x - p2.x) * (p1.x - p2.x);
    double dist2 = (p1.y - p2.y) * (p1.y - p2.y);
    return sqrt(dist1 + dist2);
}

double closestStripe(vector<point>strips,double d){
    double minn = d;
    for(int i = 0;i<strips.size(); i++){
        for(int j = i + 1 ; j<strips.size() && strips[j].y - strips[i].y < minn; j++){
            minn = min(dist(strips[i],strips[j]),minn);
        }
    }
    return minn;
}
double minimal_distanceUtil( vector<point> points){
    if(points.size() == 2)return dist(points[0], points[1]);
    if(points.size() == 3) {
        double ans1 = dist(points[0], points[1]);
        double ans2 = dist(points[0], points[2]);
        double ans3 = dist(points[1], points[2]);
        
        return min({ans1, ans2, ans3});
    }
    
    int mid = (points.size()) / 2;
    vector < point > left,right;
    for(int i = 0; i < mid; i++){
        left.push_back( points[i] );
    }
    for(int j =  mid; j < points.size(); j++){
        right.push_back( points[j] );
    }
    double dl = minimal_distanceUtil(left);
    double dr = minimal_distanceUtil(right);
    double d = min(dl,dr);
    
    vector < point > strips;
    for(int i = 0;i < points.size(); i++){
        if(abs(points[i].x - points[mid].x) < d)strips.push_back( points[i] );
    }
    sort(strips.begin(), strips.end(), compareY);
    double dstrip = closestStripe(strips,d);
    return min(dstrip,d);
}
double minimal_distance(vector<double> x, vector<double> y) {
  //write your code here
  vector<point>points(x.size());
  for(int i = 0;i < x.size(); i++){
      points[i].x = x[i];
      points[i].y = y[i];
  }
  sort(points.begin(),points.end(),compareX);
  
  return minimal_distanceUtil(points);
}

int main() {
  int n;
  std::cin >> n;
  vector<double> x(n);
  vector<double> y(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";

  
}

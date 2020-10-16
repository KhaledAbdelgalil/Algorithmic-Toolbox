#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    
    vector<int>allStops(stops.size()+2);//stop for beginning(your city) + stop for end(your destination)
    allStops[0]=0;//your city
    for(int i=1;i<stops.size()+1;i++)
     allStops[i]=stops[i-1];
    allStops[allStops.size()-1]=dist;
    
    int curr_stop_index=0;
    int last_stop_index=0;//last stop you refil at 
    int cnt_refils=0;
    while(curr_stop_index<allStops.size()){
        while(curr_stop_index+1<allStops.size()&&allStops[curr_stop_index+1]-allStops[last_stop_index]<=tank)
            curr_stop_index++;//go to last stop you can reach
        
        if(curr_stop_index==allStops.size()-1)//you have reached your final destination(no need to refil)
            break;
            
        if(curr_stop_index==last_stop_index)//you cannot move more from your last stop
            return -1;
            
        cnt_refils++;//you have reached stop that you need to refil at
        last_stop_index=curr_stop_index;//you can refil at curr_stop_index
    }
    
    return cnt_refils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

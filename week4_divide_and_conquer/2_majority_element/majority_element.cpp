#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int can(vector<int> &a,int e,int left,int right){
    int cnt=0;
    for(int i=left;i<=right;i++){
        cnt=(a[i]==e)?cnt+1:cnt;
    }
    if(cnt>(right-left+1)/2)return 1;
    return 0;
}
int get_majority_element(vector<int> &a, int left, int right) {
    // if it's just one element return it 
    if(left == right)
        return a[left];//or a[right](it doesn't matter)
    
    //if not let's split into 2 halves and get_majority_element in each
    int mid=left+(right-left)/2;
    int left_majority=get_majority_element(a,left,mid);
    int right_majority=get_majority_element(a,mid+1,right);
    
    //if it's majority in both splits => so it's dominant majority
    if(left_majority==right_majority)return left_majority;
    
    //let's see now if one of the candidates can be dominant majority in range left=>right
    if(can(a,left_majority,left,right))return left_majority;
    else if(can(a,right_majority,left,right))return right_majority;
    
    //no one is majority in left=>right
    return -1;
}


int get_majority_element2(vector<int> &a) {
    int candidate_index=0;
    int cnt=1;
    
    /* the idea behind finding the candidate is that majority is repeated almost all the array so its cnt will be always>=1*/
    //let's find a candidate
    for(int i=1;i<a.size();i++){
        if(a[candidate_index]==a[i])cnt++;
        else cnt--;
        if(cnt==0){
            candidate_index=i;
            cnt=1;
        }
    }
    cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[candidate_index]==a[i])cnt++;
    }
    if(cnt>a.size()/2)return 1;
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
    std::cout<<(get_majority_element2(a)!=-1)<<'\n';
    
}

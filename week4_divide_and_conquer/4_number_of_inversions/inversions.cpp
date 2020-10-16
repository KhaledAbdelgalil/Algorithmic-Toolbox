#include <iostream>
#include <vector>

using std::vector;
long long merge(vector<int> &a, vector<int> &b, int left, int right){
    long long number_of_inversions = 0 ;
    int i, j, k ;
    int mid = left + (right - left) / 2 ;
    i = left, j = mid + 1,k = left ;
    
    while(i <= mid && j <= right){
        if(a[i] <= a[j]){
            b[ k++ ] = a[ i++ ] ;
        }else{
            b[ k++ ] = a[ j++ ] ;
            number_of_inversions += mid - i + 1 ; // all comes after a[i] are more than a[j]
        }
    }
    
    while(i <= mid){
        b[ k++ ] = a[ i++ ] ;
    }
    while(j <= right){
        b[ k++ ] = a[ j++ ] ;
    }
    
    for(int i = left; i <= right ; i++) a[i] = b[i];
    return number_of_inversions;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {

    long long number_of_inversions = 0 ;
    if(right > left){
        int mid = left + (right - left) / 2 ;
        number_of_inversions += get_number_of_inversions(a, b, left, mid) ;
        number_of_inversions += get_number_of_inversions(a, b, mid + 1, right );
        number_of_inversions += merge(a, b, left, right);
    }
    return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}

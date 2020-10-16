#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int max1=-1,max2=-1;
    for(int i=0;i<n;i++){
        if(numbers[i]>max1)max2=max1,max1=numbers[i];
        else if(numbers[i]>max2)max2=numbers[i];
    }
    
    max_product=(long long)max1*max2;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}

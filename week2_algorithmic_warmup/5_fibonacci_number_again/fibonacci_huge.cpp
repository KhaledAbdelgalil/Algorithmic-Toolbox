#include <iostream>
#include <vector> 

unsigned long long get_len(unsigned long long n,unsigned long long m){
    unsigned long long a=0,b=1,c;
    for(unsigned long long i=0;i<n;i++){
        c = (a+b) % m;
        a = b;
        b = c;
        if(a == 0 && b == 1)return i+1;
    }
    return n+1;
}
unsigned long long get_fibonacci_huge_fast(unsigned long long n,unsigned long long m) {
    if (n <= 1)
        return n;
    
    unsigned long long required_len_seq = get_len(n,m);
    std::vector<unsigned long long>fib(required_len_seq);
    
    fib[0]=0,fib[1]=1;
    
    for(int i=2;i<fib.size();i++){
        fib[i] = (fib[i-1]+fib[i-2]) % m;
    }
    

    return fib[n%(fib.size())];
}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}

#include <iostream>
long long fib[60];
int fib_accumulative_sum[60];
void preprocessing(){
    fib[0]=0;
    fib[1]=1;
    fib_accumulative_sum[0]=0;
    fib_accumulative_sum[1]=1;
    for(int i=2;i<60;i++)fib[i]=fib[i-1]+fib[i-2],fib_accumulative_sum[i]=(fib_accumulative_sum[i-1]%10+fib[i]%10)%10;
}
int fibonacci_sum_fast(unsigned long long n) {
    if (n <= 1)
        return n;
    n=n%60;
    return fib_accumulative_sum[n];
}

int main() {
    //every period=60 the sequence is repeated
    preprocessing();
    unsigned long long n = 0;
    std::cin >> n;
    std::cout<<fibonacci_sum_fast(n)<<" ";
}

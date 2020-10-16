#include <iostream>
unsigned long long fib[61];
unsigned long long acc_fib[61];
void preprocessing(){
    //every period=60 sequence of fib % 10 repeats
    fib[0]=0,fib[1]=1;
    acc_fib[0]=0,acc_fib[1]=1;
    for(int i=2;i<61;i++) {
        fib[i]=fib[i-1]+fib[i-2];
        acc_fib[i]=(fib[i]%10+acc_fib[i-1] % 10)%10;
    }
}
int fibonacci_sum_squares_fast(unsigned long long n){
    n=n%60;
    unsigned long long side1=0;
    if(acc_fib[n]<acc_fib[n-1])side1=acc_fib[n]-acc_fib[n-1]+10;
    else side1=acc_fib[n]-acc_fib[n-1];
    side1=side1 % 10;
    
    
    unsigned long long side2=0;
    if(acc_fib[n+1] < acc_fib[n] )side2=acc_fib[n+1]-acc_fib[n]+10;
    else side2=acc_fib[n+1]-acc_fib[n];
    side2=side2 % 10;
    
    return (side1*side2) % 10;
}
int main() {
    preprocessing();
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}

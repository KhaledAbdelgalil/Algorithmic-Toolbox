#include <iostream>
#include <vector>
using std::vector;


unsigned long long fib[60]={0};
unsigned long long fib_accumulative_sum[60]={0};
void preprocessing(){
    fib[0]=0;
    fib[1]=1;
    fib_accumulative_sum[0]=0;
    fib_accumulative_sum[1]=1;
    for(int i=2;i<60;i++)fib[i]=fib[i-1]+fib[i-2],fib_accumulative_sum[i]=(fib_accumulative_sum[i-1] % 10+fib[i] % 10) % 10;
}

int get_fibonacci_partial_sum_fast(unsigned long long from,unsigned long long to) {
    to=to % 60,from=from % 60;
    if(fib_accumulative_sum[to]<fib_accumulative_sum[from-1])
        return (fib_accumulative_sum[to]+10-fib_accumulative_sum[from-1])%10;
    return (fib_accumulative_sum[to]-fib_accumulative_sum[from-1]) % 10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    //every period=60 the sequence is repeated
    preprocessing();
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}

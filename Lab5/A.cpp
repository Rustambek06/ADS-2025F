#include <iostream>
#include <queue>
#include <vector>
int main(){
    long long n, k;
    std::cin >> n;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> a;
    for(long long i = 0; i < n; i++){
        std::cin >> k;
        a.push(k);
    }
    k = 0;
    long long f, s;
    while(a.size() > 1){
        f = a.top();
        a.pop();
        k += f + a.top();
        a.push(f + a.top());
        a.pop();
    }
    std::cout << k;
}
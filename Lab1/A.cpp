#include <iostream>
#include <deque>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::deque<int> nums;
        
        int Size = N;

        while (N > 0) {
            nums.push_front(N);
            for (int i = 1; i <= N; i++) {
                int x = nums.back(); 
                nums.pop_back();
                nums.push_front(x);
            }
            N--;
        }

        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    }
}
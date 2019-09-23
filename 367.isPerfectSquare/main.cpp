#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(1 == num) return true;
        int i = num / 2;
        while((double)i * i > num) {
            i = (i + num / i) / 2;
        }
        return i * i == num;

        // while(l<=r){
        //     mid = (r+l)/2;
        //     if(mid*mid<num)
        //         l = mid+1;
        //     else if(mid*mid>num)
        //         r = mid-1;
        //     else if(mid*mid==num)
        //         return true;
        // }
        // return false;

    }
};

int main() {

    bool res = Solution().isPerfectSquare(16);

    std::cout<<res<<std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <iostream>

#include <vector>
#include <deque>

using namespace std;

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         deque<int> memo;

//         for (int i = 0; i < nums.size(); i++) {
//             if (memo.front() == i - k) memo.pop_front();

//             while (!memo.empty() && nums[memo.back()] <= nums[i]) {
//                 memo.pop_back();
//             }

//             memo.push_back(i);

//             if (i >= k - 1) {
//                 res.push_back(nums[memo.front()]);
//             }
//         }

//         return res;
//     }
// };


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;

        if (len<1)
            return res;

        int max_buff=INT_MIN;
        for (int j=0;j<k;j++)
            max_buff = max(nums[j],max_buff);

        res.push_back(max_buff);
        for(int i=k;i<len;i++){
            if (nums[i]>max_buff)
                max_buff = nums[i];
            else if(nums[i-k] == max_buff){  // 最大值不再窗口中
                max_buff=INT_MIN;
                for (int j=i-k+1;j<i+1;j++)
                    max_buff = max(nums[j],max_buff);
            }

            res.push_back(max_buff);
        }

        return res;

    }
};



int main() {

//    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums = {1,-1};
    vector<int> res = Solution().maxSlidingWindow(nums,1);

    for (auto i:res)
        std::cout << i;

    std::cout << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len<3) return 0;
        sort(nums.begin(), nums.end());
        int res = 10000;

        for(int c = len-1;c>=1; c--){
            int a=0;
            for(int b=c-1;a<b;){
                int tmp = nums[a] + nums[b] + nums[c];
                cout<<'a'<<a<<b<<c<<endl;

                if(tmp - target> 0)
                    b--;
                else if (tmp - target< 0)
                    a++;
                else{
                    return target;
                }
                cout<<"subsub"<<abs(tmp-target)<<endl;
                cout<<"res"<<res<<endl;
                if (abs(tmp-target) < abs(res-target)){
                    cout<<"ssss"<<tmp<<endl;
                    res = tmp;
                }

                // res = min(res,abs(tmp));
            }
        }

        return res;
    }
};
int main() {
    vector<int> a = {0,1,2};

    int res = Solution().threeSumClosest(a,3);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
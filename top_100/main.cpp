#include <iostream>
#include "utils.h"
#include <vector>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size()<=1) return nums.size();
    sort(nums.begin(),nums.end());
    print_vector1("name",nums);
    int res = 1;
    for(int i=1;i<nums.size();i++){
        int tmp=1;
        while(i<nums.size()){
            if(nums[i]-nums[i-1] == 1)
                tmp+=1;
            else if(nums[i]-nums[i-1] == 0)
                tmp+=0;
            else break;
            cout<<tmp<<endl;
            i++;
        }
        res = max(res,tmp);
    }
    return res;
}


int rob(vector<int>& nums) {
    int size = nums.size();
    if(size == 0 )return 0;
    if(size == 1) return nums[0];
    if(size == 2) return max(nums[0],nums[1]);
    vector<int> dp(size,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int i=2;i<size;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[size-1];
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<int>> M = {{1,2,3},{4,5,6},{7,8,9}};

    rotate(M);
    // [5,7,7,8,8,10]

    vector<int> v = {5,7,7,8,8,10};
    vector<int> res=  searchRange(v,8);
    print_vector1("name",res);

    vector<int> v8 = {1,2,3};
    vector<vector<int>> res4 = subsets(v8);
    print_vector2("subset",res4);


    vector<int> v4 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,98};
//    vector<int> v4 = {1,2,5};
    bool res5 = canPartition(v4);
    cout<<"res5---"<<res5<<endl;


    vector<int> v5 = {-4,3};

    int res6 = maxProduct(v5);
    cout<<"res6--"<<res6<<endl;

    vector<int> v10 = {-1,-1,0,1,3,4,5,6,7,8,9};

    int bb = longestConsecutive(v10);


    return 0;
}
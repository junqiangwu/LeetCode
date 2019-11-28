//
// Created by wjq on 2019/11/13.
//

#include "Solution.h"


bool Solution::makesquare(vector<int>& nums) {
    int sum = 0;
    if(nums.size()<4) return false;
    for(auto i:nums)
        sum+=i;
    if(sum%4!=0) return false;
    int target = sum/4;
    sort(nums.begin(),nums.end(),greater<int>());
    if(nums[0] > target) return false;
    vector<bool> flag(nums.size(),false);
    vector<int> sums(4,0);

    return dfs2(nums,sums,target,0);

//     return dfs(nums,flag,target,0,0,0);
}



int cnt = 0;
bool Solution::dfs2(vector<int>& nums,vector<int>& sums,int target,int start){

    cnt+=1;
    cout<<cnt<<" "<< start <<endl;

    // 搜索完了即火柴全部放入桶中，成功
    if(start == nums.size()) return true;
    // 尝试把火柴放入4个桶中
    for(int j=0;j<4;j++){
        if(sums[j] + nums[start] <= target){
            // 这里有一个非常重要的剪枝过程，即前一个桶和当前桶火柴数一致时，可以直接跳过，因为对于1根火柴来讲，两个桶如果当前大小一样，再放入时是没有区别的，而前面那个桶放入失败，则如果重新放入也肯定失败，故可以直接跳过，实测效率可以提高几十倍
            if(j==0 || sums[j] != sums[j-1]){
                //在当前桶放入火柴  并开始下一轮递归  开始放入下一根火柴
                sums[j] += nums[start];
                if(dfs2(nums,sums,target,start+1))
                    return true;
                // 放入失败，取出火彩并尝试下一个桶
                sums[j] -= nums[start];
            }
        }
    }
    // 四个桶都不能放火柴时既需要回溯，体现在上述过程中的取出操作
    return false;
}


bool Solution::dfs(vector<int>& nums,vector<bool>& flag,int target,int start,int subsum,int cnt){
    cnt+=1;
    cout<<cnt<<" "<< start <<endl;

    if(cnt==4) return true;

    if(subsum == target) return dfs(nums,flag,target,0,0,cnt+1);

    if(subsum<target){
        for(int i=start;i<nums.size();i++){
            if(flag[i] == false)
            {
                flag[i] = true;
                if(dfs(nums,flag,target,i+1,subsum+nums[i],cnt))
                    return true;
                flag[i] = false;
            }
        }
    }
    return false;
}

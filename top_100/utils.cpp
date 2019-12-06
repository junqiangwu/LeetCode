//
// Created by wjq on 2019/11/27.
//

#include "utils.h"

void print_vector2(string name,vector<vector<int>> v){
    cout<<name<<endl;
    for(auto x:v){
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}

void print_vector1(string name,vector<int> v){
    cout<<name<<endl;
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n / 2; i++) matrix[i].swap(matrix[n - 1 - i]);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> res;
    if(size == 0){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    int l=0,h=size-1;
    while(l<=h){
        int mid = (h-l)/2+l;
        if(nums[mid] > target)
            h = mid-1;
        else if(nums[mid] < target)
            l = mid+1;
        else{
            int tmp_l=mid,tmp_h=mid;
            while(tmp_l>=1 && nums[tmp_l-1]==target){
                tmp_l-=1;
            }
            while(tmp_h+1<size && nums[tmp_h+1]==target){
                tmp_h+=1;
            }
            res.push_back(tmp_l);
            res.push_back(tmp_h);
            break ;
        }
    }

    if(res.size()==0){
        res.push_back(-1);
        res.push_back(-1);
    }
    return res;
}



vector<vector<int>> subsets(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> res;
    if(size <= 1){
        res.push_back(nums);
        return res;
    }

    for(int len=1;len<=size;len++){
        for(int i=0;i+len<size;i++){
            vector<int> tmp;
            for(int k=i;k<=i+len;k++){
                tmp.push_back(nums[k]);
            }
            res.push_back(tmp);
        }
    }

    return res;
}



bool canPartition2(vector<int>& nums) {
    int size = nums.size();
    if(size <= 1) return false;
    int sum = 0;
    for(int i:nums) sum+=i;
    if(sum%2 != 0) return false;
    int target = sum/2;
    vector<vector<int>> dp(size,vector<int> (target+1,-1));

    for(int i=0;i<size;i++){
        for(int j=0;j<=target;j++){
            if(!i) dp[i][j] = (nums[i]==j);//i==0要单独求{ nums[0]一个元素和为s }
            // dp[i-1][j] 不取任何元素   dp[i-1][j-nums[i]]  装入nums[i] 这个元素
            else dp[i][j] = dp[i-1][j] || (j-nums[i]>=0 ? dp[i-1][j-nums[i]] : false);
        }
    }

    return dp[nums.size()-1][target];//[0,nums.size()-1]区间和为sum
}


bool canPartition(vector<int>& nums) {
    int size = nums.size();
    if(size <= 1) return false;
    int sum = 0;
    for(int i:nums) sum+=i;
    if(sum%2 != 0) return false;
    int target = sum/2;
    vector<int> dp(target+1,-1);

    for(int i=0;i<size;i++){
        for(int j=target ;j>=0;j--){
            if(i==0) dp[j] = (j==nums[i]);
            else{
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
    }
    return dp[target];//[0,nums.size()-1]区间和为sum
}


int maxProduct(vector<int>& nums) {
    int res = INT_MIN;
    int left_max = 1;
    // 存在0的话   置为1  开始计算新的连续子序列  [2,3,0,4]
    for (int i = 0; i < nums.size(); ++i) {
        left_max *= nums[i];
        res = max(res, left_max);
        left_max = (left_max == 0) ? 1 : left_max;
    }
    int right_max = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        right_max *= nums[i];
        res = max(res, right_max);
        right_max = (right_max == 0) ? 1 : right_max;
    }
    return res;
}


int maxProduct2(vector<int>& nums) {
    const int N=nums.size();
    vector<int> d(N),e(N);
    d[0]=nums[0];
    e[0]=nums[0];
    int ans=INT_MIN;
    ans=max(ans,max(d[0],e[0]));
    for(int i=1;i<N;++i){
        d[i]=max(nums[i],max(nums[i]*d[i-1],nums[i]*e[i-1]));
        e[i]=min(nums[i],min(nums[i]*d[i-1],nums[i]*e[i-1]));
        ans = max(ans,max(d[i],e[i]));
    }
    return ans;
}



int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    if(row<=0) return 0;
    int col = matrix[0].size();

    vector<vector<int>> dp (row+1,vector<int> (col+1,0));
    int max_val = 0;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(matrix[i][j]=='1'){
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                max_val = max(max_val,dp[i][j]);
            }
        }
    }
    return max_val;
}


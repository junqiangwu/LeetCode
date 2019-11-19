#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include "Solution.h"
#include <unordered_map>
#include <unordered_set>


using namespace std;

int a = 0;
bool dfs(vector<int>& nums,vector<bool>& flag,int subsum,int target,int k,int cnt,int start){

    if(cnt == k)
        return true;
    cout<<a<<endl;
    a++;
    if(subsum == target) {
        return dfs(nums,flag,0,target,k,cnt+1,0);
    }
    if(subsum < target){
        for(int i =start;i<nums.size();i++) {
            if (flag[i] == false) {
                flag[i] = true;
                if(dfs(nums, flag, subsum + nums[i], target, k, cnt, i + 1))
                    return true;
                flag[i] = false;
            }
        }
    }
    return false;

}


typedef pair<int,int> P;
void bfs(vector<vector<char>>& grid,int x,int y,int rows,int cols){
    queue<P> mq;
    mq.push(P(x,y));
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    while(!mq.empty()){
        x = mq.front().first;
        y = mq.front().second;
        mq.pop();
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<rows && newy>=0 && newy<cols && grid[newx][newy] == '1'){
                grid[newx][newy] = '0';
                mq.push(P(newx,newy));
            }
        }
    }
}


int numIslands(vector<vector<char>>& grid) {
    int islandNum = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                bfs(grid, i, j,grid.size(),grid[0].size());
                islandNum++;
            }
        }
    }
}




bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for(auto i:nums)
        sum+=i;

    if(sum%k != 0)
        return false;

    int target = sum/k;
    sort(nums.begin(), nums.end(), greater<int>());
//    sort(nums.begin(), nums.end());
//    if(nums[0] > target) return false;

    vector<bool> flag(nums.size(), false);

    return dfs(nums,flag,0,target,k,0,0);
}



int main() {
    vector<int> vec = {3,9,4,4,20,15,4,4,7,4,4};
    TreeNode* root;
    Solution solution;

//    solution.Creat_Tree(root);
    int i =0;
    vector<int> v = {1,2,1,3,2,5};

//    bool res = canPartitionKSubsets(v,4);
//    cout<<res<<endl;

    unordered_map<int,int> mp;
    for (int number : v)
    {
        //在 C++ 中，通过 unordered_set 的 insert 方法添加元素时
        //将返回一个 pair<iterator, bool> 对象
        //其 second 为一布尔类型的值，标识是否添加成功
        //注意逻辑非(!)操作符
        if (!mp.insert(pair<int,int>(number,number)).second)
            mp.erase(number);;//重复便移除
    }
    cout<<mp.size()<<endl;

    for(auto i:mp)
        cout<<i.second<<" ";
    cout<<endl;



    std::cout << "Hello, World!" << std::endl;
    return 0;
}

//
//int main() {
//    vector<int> vec = {3,9,4,4,20,15,4,4,7,4,4};
//    TreeNode* root;
//    Solution solution;
//
////    solution.Creat_Tree(root);
//    int i =0;
//    vector<int> v = {1,2,0,0,3,0,0};
//    vector<int> v2 = {-10,9,0,0,20,15,0,0,7,0,0,0};
//
//    vector<int> v3 = {3,9,0,0,20,15,0,0,7,0,0,0};
//    solution.Creat_Tree_2(root,v3,i);
//
//    solution.Print_Tree(root,0);
//
////    int res = solution.maxPathSum(root);
//    int res = solution.sumOfLeftLeaves(root);
//
//    cout<<res<<endl;
//
//
////    solution.zigzagLevelOrder(root);
//
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
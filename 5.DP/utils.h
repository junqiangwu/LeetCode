//
// Created by wjq on 2019/11/16.
//

#ifndef INC_5_DP_UTILS_H
#define INC_5_DP_UTILS_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

#include <set>
#include <unordered_set>
#include <stack>

using namespace std;

typedef struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
}TreeNode;
void print_vector1(string name,vector<vector<int>> v);
void print_vector2(string name,vector<vector<int>> v);


string longestPalindrome(string s);
string longestPalindrome_DP(string s);
int rob(vector<int>& nums);
int coinChange(vector<int>& coins, int amount);
int coinChange_DFS(vector<int>& coins, int amount);
int coinChange_dp(vector<int>& coins, int amount);

// 62-63
int uniquePaths(int m, int n);
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

// 64.
int minPathSum(vector<vector<int>>& grid);

int integerBreak(int n);

// 474 一和零
int findMaxForm(vector<string>& strs, int m, int n);

int package_01(vector<int>& w,vector<int>& v,int c);


string largestTimeFromDigits(vector<int>& A);

// 416. 分割等和子集
bool canPartition(vector<int>& nums);


//39 组合总和
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

//46 全排列
vector<vector<int>> permute(vector<int>& nums);
vector<vector<int>> permuteUnique(vector<int>& nums);

// 60. 第k个排列
string getPermutation(int n, int k);


vector<vector<int>> combine(int n, int k);

// 300 最长上升子序列
int lengthOfLIS(vector<int>& nums);

int findDuplicate(vector<int>& nums);

// 221 最大正方形
int maximalSquare(vector<vector<char>>& matrix);

// 560 和为k的子数组
int subarraySum(vector<int>& nums, int k);

//120 三角形最小和
int minimumTotal(vector<vector<int>>& triangle);

//931. 下降路径最小和
int minFallingPathSum(vector<vector<int>>& A);


//368. 最大整除子集
vector<int> largestDivisibleSubset(vector<int>& nums);

//718 最长重复子数组
int findLength(vector<int>& A, vector<int>& B);

//673. 最长递增子序列的个数
int findNumberOfLIS(vector<int>& nums);
#endif //INC_5_DP_UTILS_H

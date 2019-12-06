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
#include <stack>

using namespace std;

typedef struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
}TreeNode;


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

#endif //INC_5_DP_UTILS_H

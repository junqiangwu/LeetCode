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

using namespace std;

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


#endif //INC_5_DP_UTILS_H

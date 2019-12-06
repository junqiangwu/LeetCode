//
// Created by wjq on 2019/11/27.
//

#ifndef TOP_100_UTILS_H
#define TOP_100_UTILS_H

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





void print_vector2(string name,vector<vector<int>> v);
void print_vector1(string name,vector<int> v);


void rotate(vector<vector<int>>& matrix);
vector<int> searchRange(vector<int>& nums, int target);

// 78. 子集
vector<vector<int>> subsets(vector<int>& nums);

//416. 分割等和子集
bool canPartition(vector<int>& nums);

// 152 乘积最大的连续子序列
int maxProduct(vector<int>& nums);

// 221. 最大正方形
int maximalSquare(vector<vector<char>>& matrix);
#endif //TOP_100_UTILS_H

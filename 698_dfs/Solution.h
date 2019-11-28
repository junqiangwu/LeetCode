//
// Created by wjq on 2019/11/13.
//

#ifndef INC_698_DFS_SOLUTION_H
#define INC_698_DFS_SOLUTION_H

#include <iostream>
#include "Solution.h"
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums);
    bool dfs2(vector<int>& nums,vector<int>& sums,int target,int start);
    bool dfs(vector<int>& nums,vector<bool>& flag,int target,int start,int subsum,int cnt);

};


#endif //INC_698_DFS_SOLUTION_H

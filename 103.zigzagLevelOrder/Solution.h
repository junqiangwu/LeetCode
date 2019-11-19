//
// Created by wjq on 2019/10/11.
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#ifndef INC_103_ZIGZAGLEVELORDER_SOLUTION_H
#define INC_103_ZIGZAGLEVELORDER_SOLUTION_H


typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*PTREE;

// typedef TreeNode* PTREE;

class Solution {
public:
    void Creat_Tree(PTREE& Root);

    void Print_Tree(const PTREE Root,int space);
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);
    int maxPathSum(TreeNode* root) ;
    void Creat_Tree_2(PTREE& Root,vector<int> v,int& sum);

    int sumOfLeftLeaves(TreeNode* root);
};


#endif //INC_103_ZIGZAGLEVELORDER_SOLUTION_H

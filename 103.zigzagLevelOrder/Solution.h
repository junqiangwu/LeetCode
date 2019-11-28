//
// Created by wjq on 2019/10/11.
//
<<<<<<< HEAD
=======
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
>>>>>>> 77d679a68de628c28f069f0b64030037dac4cfd1

#ifndef INC_103_ZIGZAGLEVELORDER_SOLUTION_H
#define INC_103_ZIGZAGLEVELORDER_SOLUTION_H


<<<<<<< HEAD
class Solution {

=======
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
>>>>>>> 77d679a68de628c28f069f0b64030037dac4cfd1
};


#endif //INC_103_ZIGZAGLEVELORDER_SOLUTION_H

//
// Created by wjq on 2019/10/9.
//

#ifndef INC_144_TWO_TREE_SOLUTION_H
#define INC_144_TWO_TREE_SOLUTION_H

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    void CreatTree(TreeNode& Root);


};


#endif //INC_144_TWO_TREE_SOLUTION_H

//
// Created by wjq on 2019/10/9.
//

#ifndef INC_144_TWO_TREE_SOLUTION_H
#define INC_144_TWO_TREE_SOLUTION_H

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode,*PTREE;

class Solution {

public:
    void CreatTree(PTREE& Root);
    void CreatTree_2(PTREE& Root);

};


#endif //INC_144_TWO_TREE_SOLUTION_H

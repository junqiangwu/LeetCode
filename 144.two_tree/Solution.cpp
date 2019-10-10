//
// Created by wjq on 2019/10/9.
//

#include "Solution.h"


//输入 abc***de**fg***  建立先序遍历为abcdefg的普通树
//需要修改指向 树结构的 指针,所以形参为 指针的引用(指针的指针)
TreeNode* Solution::CreatTree(){
    char a=0;
    a = getchar();
    if(a=='*'){
        Root = NULL;
    }
    else{
        Root = (TreeNode *)malloc(sizeof(TreeNode));
        if(Root==NULL)
            printf("Failed");
        else{
            Root->data = a;
            CreatTree(Root->left);
            CreatTree(Root->right);
        }
    }
}


void order(TreeNode* root,vector<int>& res) {
     if(root==nullptr) return ;
     res.push_back(root->val);
     order(root->left,res);
     order(root->right,res);
}

vector<int> preorderTraversal(TreeNode* root) {
     vector<int> res;
     order(root,res);
     return res;
}


vector<int> preorderTraversal2(TreeNode* root) {

    vector<int> res;
    if(root==nullptr) return res;
    stack<TreeNode*> ms;
    ms.push(root);

    while(!ms.empty()){
        TreeNode* tmp = ms.top();
        ms.pop();
        res.push_back(tmp->val);

        if(tmp->right)
            ms.push(tmp->right);

        if(tmp->left)
            ms.push(tmp->left);
    }

    return res;
}

vector<int> preorderTraversal(TreeNode* root) {

    vector<int> res;
    if(root==nullptr) return res;
    stack<TreeNode*> my_s;
    TreeNode* cur=root;

    while(cur!=NULL || !my_s.empty()){

        while(cur!=NULL){
            res.push_back(cur->val);
            my_s.push(cur);
            cur = cur->left;
        }

        if(!my_s.empty()){
            cur = my_s.top();
            my_s.pop();
        }
        cur = cur->right;
    }
    return res;
}
//
// Created by wjq on 2019/10/11.
//

#include "Solution.h"



int pathSum(TreeNode* root,int& sum){
    if(!root) return 0;
    int left = 0,right = 0;
    left = max(pathSum(root->left,sum),0);
    right = max(pathSum(root->right,sum),0);
    sum = max(sum,root->val+left+right);
    return root->val+max(0,max(left,right));
}


int Solution::maxPathSum(TreeNode* root) {
    int res = 0;
    if(!root) return res;
    pathSum(root,res);
    cout<<root->val<<"----"<<res<<endl;
    return res;
}


void Solution::Creat_Tree_2(PTREE& Root,vector<int> v,int& sum) {
    int b=0 ;
    b = v[sum];
    sum += 1;
    if (b==0){
        Root=NULL;
    }else{
        Root = new TreeNode(0);
        Root->val = b;

        Creat_Tree_2(Root->left,v,sum);

        Creat_Tree_2(Root->right,v,sum);
    }
}



void Solution::Creat_Tree(PTREE& Root) {
    int b=0 ;
    cout<<"input:";
    std::cin>>b;
    if (b==0){
        Root=NULL;
    }else{
        Root = new TreeNode(0);
        Root->val = b;
        Creat_Tree(Root->left);
        Creat_Tree(Root->right);
    }
}

void Solution::Print_Tree(const PTREE Root,int space){
    if(Root == NULL ) return ;

    Print_Tree(Root->right,space+4);
    for(int i=0;i<space;i++) printf(" ");
    printf("%d \n", Root->val);
    Print_Tree(Root->left,space+4);
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(!root) return res;
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while(!q.empty())
    {
        vector<int> out;
        int size = q.size(); //取得每一层的长度
        for(int i = 0; i < size; i++)
        {
            auto temp = q.front();
            q.pop();
            out.push_back(temp->val);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        if(flag%2==1)
        {
            reverse(out.begin(),out.end());
        }
        res.push_back(out);
        flag++;
    }
    return res;
}



int Solution::sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    if(!root) return 0;

    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
        sum += root->left->val;
        return root->left->val;
    }

    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);

//    return  sum;
}

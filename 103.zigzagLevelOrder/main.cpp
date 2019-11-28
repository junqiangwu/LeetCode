#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Solution.h"

using namespace std;




int main() {
    vector<int> vec = {3,9,4,4,20,15,4,4,7,4,4};
    TreeNode* root;
    Solution solution;

    solution.Creat_Tree(root);

    solution.Print_Tree(root,1);

//    solution.zigzagLevelOrder(root);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
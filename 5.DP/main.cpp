#include <iostream>
#include "utils.h"

int main() {

//    int res = uniquePaths(7,3);
//    cout<<res<<endl;
//
//    vector<vector<int>> grid = {{0,1}};
//
//    cout<< uniquePathsWithObstacles(grid)  <<endl;
//
//    vector<vector<int>> grid2 ={{1,3,1},
//                                {1,5,1},
//                                {4,2,1}};
//
//    cout<< minPathSum(grid2)  <<endl;
//
//    cout << integerBreak(11) <<endl;


    vector<int> weights = {0,2,3,4,5};
    vector<int> cost = {0,3,4,5,6};
    int res2 = package_01(weights,cost,8);

    cout<<res2<<endl;

    vector<int> time = {1,2,3,5};
    string aa = largestTimeFromDigits(time);
    cout<<aa<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
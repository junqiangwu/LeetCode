#include <iostream>
#include "utils.h"

int main() {
    vector<int> v1 ={1,2,3,5};

      int aa = coinChange_dp(v1,10);
      cout<<aa<<endl;

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


    /*  39-40 全组合
    vector<int> candidates = {2,3,5};
    vector<vector<int>> a_39 = combinationSum(candidates,8);
    print_vector2("combinationSum",a_39);

    vector<int> candidates2 = {10,1,2,7,6,1,5};
    vector<vector<int>> a_40 = combinationSum2(candidates2,8);
    print_vector2("combinationSum2",a_40);
    */

    vector<int> nums{1,1,2};
    vector<vector<int>> res = permute(nums);
    print_vector2("permute",res);

    vector<vector<int>> res2 = permuteUnique(nums);
    print_vector2("permute2",res2);

    string res3 = getPermutation(3,3);

    cout<<res3<<endl;

    vector<vector<int>> res4 = combine(4,2);
    print_vector2("combine",res4);


    vector<int> v4 = {1,3,6,7,9,4,10,5,6};
    int res5 = lengthOfLIS(v4);
    cout<<"res---"<<res5<<endl;

    vector<int> cc{1,2,4,3,5,4,7,2};
    int res6 = findNumberOfLIS(cc);
    cout<<"res---"<<res6<<endl;

    return 0;
}
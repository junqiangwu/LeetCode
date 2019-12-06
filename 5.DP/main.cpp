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

    vector<int> v = {1,1,2,4,3};

    cout<<findDuplicate(v)<<endl;

    vector<vector<char>> matrix = {{'1' ,'0' ,'1' ,'0' ,'0'},
                                  {'1' ,'0' ,'1' ,'1' ,'1'},
                                  {'1' ,'1' ,'1' ,'1' ,'1'},
                                  {'1' ,'0' ,'0' ,'1' ,'0'}};

//    vector<vector<char>> matrix = {{'1'}};

    int res8 = maximalSquare(matrix);
    cout<<"matrix--"<<res8<<endl;

    vector<int> v12 = {1,3,5,1,3,3,4};
    int res12 = subarraySum(v12,4);
    cout<<"res12--"<<res12<<endl;

    vector<vector<int>> triangle = {{2},
                                    {3,4},
                                    {6,5,7},
                                    {4,1,8,3}};
    int bb = minimumTotal(triangle);
    cout<<"rbb---"<<bb<<endl;



//    {{51,24},
//        {-50,82}};
    vector<vector<int>> A =     {{1,2,3},
                                 {4,5,6},
                                 {7,8,9}};

    int cc = minFallingPathSum(A);
    cout<<"cc---"<<cc<<endl;

    vector<int> B = {4,8,10,240};
    vector<int> vv = largestDivisibleSubset(B);
    for (int i:vv)
        cout<<i<<" ";
    cout<<endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
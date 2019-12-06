#include <iostream>
#include "utils.h"


int main() {
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','E','S'},
                                  {'A','D','E','E'}};

//    bool res = exist(board,"ABCESEEEFS");

    vector<int> v {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100};
    cout<<"size--"<<v.size()<<endl;
    int sum = 0;
    for (int i:v) sum+=i;
    cout<<"sum"<<sum<<endl;

//    bool res2 = canPartition(v);
//    cout<<"res2---"<<res2<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
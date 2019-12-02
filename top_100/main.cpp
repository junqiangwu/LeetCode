#include <iostream>
#include "utils.h"
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<int>> M = {{1,2,3},{4,5,6},{7,8,9}};

    rotate(M);
    // [5,7,7,8,8,10]

    vector<int> v = {5,7,7,8,8,10};
    vector<int> res=  searchRange(v,8);
    print_vector1("name",res);

    vector<int> v8 = {1,2,3};
    vector<vector<int>> res4 = subsets(v8);
    print_vector2("subset",res4);

    return 0;
}
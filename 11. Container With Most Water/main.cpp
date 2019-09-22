#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {
        int res=0;
        int len = height.size();
//         if (len<2)
//             return res;
        int l=0,r=len-1;

        int flag=0;
        while(l<r){

            cout<<height[l]<<height[r]<<(r-l)<<endl;

            int water = min(height[l],height[r])*(r-l);

            res = max(res,water);
            if (height[l] < height[r])
                l++;
            else
                r--;

        }
        return res;

    }
};

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {

//    vector<int> v={1,8,6,2,5,4,8,3,7};
    vector<int> v={2,3,10,5,7,8,9};

    int ret = Solution().maxArea(v);

//    string out = integerVectorToString(ret);

    std::cout<<ret<<endl;
    std::cout<<(pow(10,2));

}
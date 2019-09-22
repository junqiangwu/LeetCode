#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int l=0,r=len-1;
        vector<int> res;
        cout<<r<<endl;
        while( l<r ){
            if (numbers[l] + numbers[r] == target )
            {   res.push_back(l);
                res.push_back(r);
                break;
            }
            else if (numbers[l] + numbers[r] > target)
                r--;
            else if (numbers[l] + numbers[r] < target)
                l++;
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

    vector<int> v={3,2,4};

    vector<int> ret = Solution().twoSum(v, 6);

    string out = integerVectorToString(ret);

    std::cout<<out<<endl;
    std::cout<<(pow(10,2));

}
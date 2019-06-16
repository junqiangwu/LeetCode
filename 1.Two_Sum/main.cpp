#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> vec;

        int len = nums.size();

        for (int i=0;i<len;i++){

            if (m.find(target-nums[i])!=m.end()){
                vec.push_back(i);
                vec.push_back(m[target-nums[i]]);
                return vec;
            }else{
                m[nums[i]] = i;
            }
        }

        return vec;
    }


    vector<int> twoSum_2(vector<int>& nums, int target) {
        vector<int> vec;

        int len = nums.size();

        for (int i=0;i<len;i++){
            for (int j=i+1;j<len;j++){
                if (nums[i]+nums[j] == target) {
                    vec.push_back(i);
                    vec.push_back(j);
                    return vec;
                }
            }
        }

        return vec;
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

    vector<int> v={1,2,3,4,5,6,7};

    vector<int> ret = Solution().twoSum_2(v, 20);

    string out = integerVectorToString(ret);

    std::cout<<out<<endl;

}
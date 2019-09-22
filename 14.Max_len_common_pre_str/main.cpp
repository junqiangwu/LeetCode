#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len_s = strs.size();

        if(len_s ==0) return "";
        if(len_s == 1) return strs[0];
        int min_len = INT_MAX;
        for(int i=0;i<len_s;i++){
            int a = strs[i].size();
            min_len = min(min_len,a);
        }

        string res = strs[0].substr(0,min_len);

        for(int i=1;i<len_s;i++){
            int j =0;
            while(j<min_len){
                if(res[j] != strs[i][j]){
                    res = res.substr(0,j);
                    break;
                }
                j++;
            }
        }

        return res;

    }
};

int main() {
    vector<string> a ={"aa","a"};

    string res = Solution().longestCommonPrefix(a);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
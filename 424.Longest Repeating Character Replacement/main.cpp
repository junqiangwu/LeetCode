#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0); //记录当前窗口字母出现的个数
        int left=0, res=0, maxCnt=0; // maxCnt记录字符出现次数最多那个字符 的次数
        for(int i=0; i<s.size(); i++){
            counts[s[i]-'A']++;
            maxCnt = max(maxCnt, counts[s[i]-'A']); // 比较之前记录的最大数 和 当前字符的数量
            while(i-left+1-maxCnt > k){ // 若当前窗口大小 减去 窗口中最多相同字符的个数 大于 k 时
                counts[s[left]-'A']--; // 将窗口最左边的字符 在计数数组中减1
                left++; // 滑动窗口
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};


int main() {

    string s = "AABABBA";
    int res = Solution().characterReplacement(s,1);

    std::cout << res << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
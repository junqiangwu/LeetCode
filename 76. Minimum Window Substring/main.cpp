#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution2{
public:
    string minWindow(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();

        string res = "";
        if (len_s<1 || len_t<1)
            return res;

        int min_size = INT_MAX;

        vector<int> freq(128, 0);
        int l=0,r=-1;

        for(int i=0;i<len_t;i++)
            freq[t[i]]++;

        int count=0;
        for(;r+1<len_s;){

            freq[s[++r]]--;

            if(freq[s[r]]>=0)
                ++count;

            while(count == len_t){

                if( (r-l+1) < min_size)
                {
                    min_size = r-l+1;
                    res = s.substr(l, min_size);
                }

                if (freq[s[l]] >= 0) {
                    --count;
                }

                ++freq[s[l]];
                ++l;
            }

        }

        return res;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tmap(128, 0);
        for (char c : t) {
            ++tmap[c];
        }
        string res = "";
        int counts = 0, minwin = INT_MAX, left = 0;
        for (int i=0; i<s.size(); ++i) {
            --tmap[s[i]];
            if (tmap[s[i]] >= 0) {
                ++counts;
            }
            while (counts == t.size()) {
                if (minwin > i-left+1) {
                    minwin = i-left+1;
                    res = s.substr(left, minwin);
                }
                if (tmap[s[left]] >= 0) {
                    --counts;
                }
                ++tmap[s[left]];
                ++left;
            }
        }
        return res;
    }
};

int main() {
    string S = "ADOBECODDEBANC";
    string T = "ABC";


    string res = Solution2().minWindow(S,T);

    std::cout << res << std::endl;

    std::cout << 1111 << std::endl;
    return 0;

}
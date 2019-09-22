#include <iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len_s = ransomNote.size();
        int len_m = magazine.size();

        if (len_m<len_s) return 0;
        if (len_s == 0) return 1;

        cout<<len_s<<len_m<<endl;

        int freq[26] = {0};
        for (int i=0;i<len_s;i++){
            freq[ ransomNote[i] - 'a']++;
        }
        int num = 0;
        for(int i=0;i<len_m;i++){
            freq[ magazine[i] - 'a'] --;
            if (freq[ magazine[i] - 'a'] >= 0)
                num+=1;

            if (num == len_s)
                return 1;
        }
        return 0;

    }
};


int main() {
    string a = "";
    string b = "";

    bool res = Solution().canConstruct(a,b);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
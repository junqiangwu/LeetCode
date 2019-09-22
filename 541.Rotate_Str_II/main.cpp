#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    string reverseStr(string s, int k) {
        int len = s.size();

        int i=0;
        for (;i<=len-k;){
            if(i%(2*k) == 0) {
                char buff;
                for (int j = 0; j < int(k / 2); j++) {
                    buff = s[j + i];
                    s[j + i] = s[i + k - j - 1];
                    s[i + k - j - 1] = buff;
                }
            }
            i+=k;
        }

        string::iterator it=s.begin();
        if( i+k > len && (i-k)%(2*k) !=0 ){
            reverse(it+i,s.end());
        }

        return s;
    }
};

int main() {
    vector<char> v = {'h','e','a','l','o','c'};
    string s = "abcdefg";

    string res = Solution().reverseStr(s,4);
    cout<<res<<endl;

    for (int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<0<<endl;
    return 0;
}

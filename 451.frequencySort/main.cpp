#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int i=0;
        unordered_map<char,int> m;
        for(auto c:s)
            i = max(i,++m[c]);
        string res;
        cout<<i<<endl;
        while(res.size()<s.size()){
            for(auto p:m){
                cout<<p.first<<p.second<<endl;
                if(p.second == i){
                    for(int j=0;j<i;j++)
                        res.insert(res.end(),p.first);
                }
            }
            --i;
        }

        return res;
    }
};


int main() {
    string s = "tree";
    string res = Solution().frequencySort(s);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <algorithm>
using namespace std;

class Solution {
public:

    string reverseWords(string s) {
    	
    	string::iterator it = s.begin();
    	string::iterator it_ = it;

    	for(;it<=s.end();it++){
//    	    cout<<*it;
    		if(*it == ' ' || *it == '\0'){
    			reverse(it_,it);
    			it_ = it+1;
    		}

    	}
    	return s;
    }
};

int main() {
    vector<char> v = {'h','e','a','l','o','c'};
    string s = "Let's take LeetCode contest";

    
    
    string res = Solution().reverseWords(s);
    
    cout<<res<<endl;

    for (int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<0<<endl;
    return 0;
}

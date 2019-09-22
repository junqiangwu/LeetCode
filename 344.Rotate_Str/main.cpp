#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	void reverseString(vector<char>& s) {
        int len = s.size();
        char buff;
        for(int i=0;i<int(len/2);i++){
            buff = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = buff;
            cout<<buff<<endl;
        }
    }

	string reverseStr(string s, int k) {
        int len = s.size();
       	if (len<k) return s;
       	for (int i=0;i<len-2*k;i++){

       		for(int j=0;j<int(k/2);j++){
       			
       		}

       	}

    }


};

int main() {
    vector<char>v = {'h','e','a','l','o','c'};

    Solution().reverseString(v);

    for (int i=0;i<v.size();i++){
        cout<<v[i];
    }

    return 0;
}

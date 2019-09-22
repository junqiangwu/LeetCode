#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include<algorithm>

#include <string>

using namespace std;



class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size()<1)
            return res;

        vector<string> buff = strs;
        map<string,vector<string>> my_map;
        string b;
        for(int i=0;i<strs.size();i++){

            sort(buff[i].begin(),buff[i].end());
//            cout<<strs[i]<<endl;
            my_map[buff[i]].push_back(strs[i]);
        }
        for(auto &v : my_map){
            res.push_back(v.second);
        }
        return res;
    }

//
//    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
//        vector<vector<string>> res;
//        if (strs.size()<1)
//            return res;
//        // vector<string> buff = strs;
//        map<string,vector<string>> my_map;
//
//        for(int i=0;i<strs.size();i++){
//            int freq[26] = {0};
//            std::string key = " ";
//            for(auto k:strs[i])
//                freq[k]++;
//            for(int j=0;j<26;j++){
//                key.insert(1,'a');
//            }
//            my_map[key].push_back(strs[i]);
//        }
//        for(auto &v : my_map){
//            res.push_back(v.second);
//        }
//        return res;
//    }

//    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
//        vector<vector<string>> res;
//        if (strs.size()<1)
//            return res;
//        // vector<string> buff = strs;
//        map<int [26],vector<string>> my_map;
//        // string b;
//        for(int i=0;i<strs.size();i++){
//            struct my freq = {0};
//            for(auto k:strs[i])
//            {
//                freq[k-'a']++;
//                cout<<k;
//            }
//            for(auto k:freq)
//                cout<<k;
//            cout<<endl;
//
//            // sort(buff[i].begin(),buff[i].end());
//            my_map[freq].push_back(strs[i]);
//        }
//        for(auto &v : my_map){
//            res.push_back(v.second);
//        }
//        return res;
//    }

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

    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};

//    vector<int> v={3,2,4};
//
    vector<vector<string>> ret = Solution().groupAnagrams(v);
//
//    string out = integerVectorToString(ret);
//    for (auto &i:ret)
//        for (auto &j:i)
//            std::cout<<j<<endl;

    std::cout<<(pow(10,2));

}
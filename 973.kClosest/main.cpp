#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:

//    struct cmp{
//        bool operator()(vector<int> a,vector<int> b){
//            return sqrt(pow(a[0], 2) + pow(a[1], 2)) > sqrt(pow(b[0], 2) + pow(b[1], 2));
//        }
//    };

    inline int distance2(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        // sort(points.begin(), points.end(), cmp);
        // return vector<vector<int>>(points.begin(), points.begin() + K);
        // priority_queue< vector<int>, vector<vector<int>>, cmp > pq;

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<points.size();i++){
             pq.push( make_pair(distance2(points[i]),i));
//            if(pq.size() < K)
//                pq.push(make_pair(distance2(points[i]), i));
//            else if(distance2(points[i]) < pq.top().first)
//            {
//                pq.pop();
//                pq.push(make_pair(distance2(points[i]), i));
//            }
        }

        int index = 0;
        while(!pq.empty()&&index++!=K){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }


    // 利用优先队列的特性，首先弹出优先级比较高的元素
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> res;
        int i=0;
        for(auto num:nums)
            m[num]++;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
//        priority_queue< pair<int,int>, vector<pair<int,int>> > pq;

//        for(auto p:m){
//            pq.push( make_pair(p.second,p.first));
//        }


        for(auto p:m){
            if(pq.size() == k){
                if(p.second > pq.top().first){
                    pq.pop();
                    pq.push( make_pair(p.second,p.first));
                }
            }else{
                pq.push( make_pair(p.second,p.first));
            }
        }

        while(!pq.empty()){
            cout<<"111--"<<pq.top().second<<"-"<<pq.top().first<<endl;
            pq.pop();
        }

//        int index = 0;
//        while(!pq.empty() && index++!=k){
//            res.push_back(pq.top().second);
//            pq.pop();
//        }

        return res;
    }

};


int main() {

    vector<vector<int>> v= {{3,3},{5,1},{-2,4}};

//    vector<vector<int>> res = Solution().kClosest(v,2);

//    for(auto i:res)
//        for(auto j:i)
//            cout<<j<<" ";
//        cout<<endl;

    vector<int> a = {1,1,1,1,1,2,2,2,2,4,5,5,7,7,8,8,9,9,9};
    vector<int> res2 = Solution().topKFrequent(a,2);

//    for (auto i :res2)
//        cout<<i<<" ";
//    cout<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
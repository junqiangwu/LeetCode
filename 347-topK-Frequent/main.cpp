#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using  namespace std;

class Solution {
public:
    /*
    struct cmp{
        bool operator()(vector<int> a,vector<int> b){
            return sqrt(a[0]*a[0]+a[1]*a[1]) > sqrt(a[0]*a[0]+a[1]*a[1]);
        }
    };
    */

    struct cmp{
        bool operator()(int a,int b){
            return a%10 < b%10;
        }
    };

    static bool cmp2(int a,int b){ return a%10 > b%10;}

    // 出现频率 topk 的元素
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> res;
        using E = pair<int,int>;
        // priority_queue 三个参数 数据类型  存储数据用的容器(数组实现的容器vector,deque)  比较函数
        priority_queue< E, vector<E>, greater<E> > pq;
        for(auto i:nums)
            m[i]++;

        for(auto i:m){
            if(pq.size()==k){

                if(i.second > pq.top().first) {
                    pq.push(make_pair(i.second, i.first));
                    pq.pop();
                }
            }else {
                pq.push(make_pair(i.second, i.first));
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    // 优先队列实现的比较函数
    vector<int> RandomSample(vector<int> v){
        vector<int> res;
        priority_queue< int, vector<int>, cmp> pq;

        for(auto i:v){
            pq.push(i);
        }

        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }

    // 修改sort的内置比较函数
    vector<int> RandomSample_v2(vector<int> v){
        sort(v.begin(),v.end(),cmp2);
        return v;
    }

    bool isPossible(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> s_m;
        unordered_map<int,int> e_m;

        for(auto i:nums)
            s_m[i]++;

        for(int i=0;i<nums.size();i++){

            if(s_m[ nums[i] ] == 0)
                continue;
            s_m[ nums[i] ] -= 1;

            if(e_m[nums[i]-1] > 0 ){
                e_m[ nums[i]-1 ] -= 1;
                e_m[ nums[i] ] += 1;
            }else if( s_m[ nums[i]+1 ] >0 && s_m[ nums[i]+2 ]>0){
                s_m[ nums[i]+1 ] -= 1;
                s_m[ nums[i]+2 ] -= 1;
                e_m[ nums[i]+2 ] += 1;
            }else
                return false;
        }
        return true;
    }

};


void Print_Vec(vector<int> a){
    cout<<"[";
    for(auto i:a)
        cout<<i<<" ";
    cout<<"]"<<endl;
}

vector<int> Rand(int s,int e,int n){
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int a = s + rand()%(e-s);
        res.push_back(a);
    }
    return res;
}

int main() {

    vector<int> v = {5,4,4,3,3,3,2,2,2,1,1,1,1};

    vector<int> res = Solution().topKFrequent(v,4);
    Print_Vec(res);

    vector<int> rand_seed = Rand(0,50,10);

    Print_Vec(rand_seed);
    Print_Vec(Solution().RandomSample(rand_seed));
    Print_Vec(Solution().RandomSample_v2(rand_seed));

    vector<int> bb = {1,2,3,3,4,5};
    cout<<Solution().isPossible(bb)<<endl;


    clock_t start,end;
    start = clock();
    for (int i = 0; i < 1000000; i++)
    {
        i++;
    }
    end = clock();
    cout << "Totle Time : " <<(double)(end - start)*1000 / CLOCKS_PER_SEC << "ms" << endl;

    return 0;
}
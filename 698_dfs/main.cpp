#include <iostream>
#include "Solution.h"
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;


//vector<int> a(10,0);

int a[10];
void test(){
    int a2[10];
    int a3[10] = {1};
    static int a4[10];

    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for(int i=0;i<10;i++)
        cout<<a2[i]<<" ";
    cout<<endl;

    for(int i=0;i<10;i++)
        cout<<a3[i]<<" ";
    cout<<endl;

    for(int i=0;i<10;i++)
        cout<<a4[i]<<" ";
    cout<<endl;

    int a5[10];
    memset(a5,1,10*sizeof(int));
    for(int i=0;i<10;i++)
        cout<<a5[i]<<" ";
    cout<<endl;

}


int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1,0);
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2;i<=cost.size();i++){
        dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }

    for(auto i:dp)
        cout<<i<<" ";
    cout<<endl;

//    return dp[cost.size()-1]+cost[cost.size()-1];
    return dp[cost.size()];
}

int minCostClimbingStairs2(vector<int>& cost,vector<int>& dp,int n) {
    if(n<=0) return dp[0];
    if(n==1) return dp[1];

    int tmp = minCostClimbingStairs2(cost,dp,n-1)+cost[n-1];
    int tmp2 = minCostClimbingStairs2(cost,dp,n-2)+cost[n-2];
    dp[n] = min(tmp,tmp2);

//    cout<<"n"<<n<<endl;
//    for(auto i:dp)
//        cout<<i<<" ";
//    cout<<endl;

    return dp[n];
}

int main() {
    set<vector<int>> ms;
//    vector<int> aaa = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> aaa = {0,0,0,1};
    vector<int> dp(aaa.size()+1,0);

//    int abc2 = minCostClimbingStairs(aaa);

    cout<<"a"<<endl;
    int abc = minCostClimbingStairs2(aaa,dp,aaa.size()+1);

    for(auto i:dp)
        cout<<i<<" ";
    cout<<endl;

    cout<<"abc"<<abc<<endl;

    vector<int> obj(10,1);
    vector<vector<int>> aa(10,obj);

//    test();

    static int mq[10];

    for(auto i:mq)
        cout<<i<<" ";
    cout<<endl;
//
//    for(auto i:obj)
//        cout<<i<<" ";
//    cout<<endl;

//    for(auto i:aa){
//        for(auto j:i)
//            cout<<j<<" ";
//        cout<<endl;
//    }


    vector<int> v = {1,1,2,2,2};
    Solution solution;

    for(int i=0;i<4;i++){
        ms.insert(v.begin(),v.begin()+i);
    }
    for(auto i:ms)
        cout<< i[0] <<" ";
    cout<<endl;

    bool res = solution.makesquare(v);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
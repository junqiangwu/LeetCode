//
// Created by wjq on 2019/11/16.
//

#include "utils.h"


bool isPalindromic(string s){
    int size = s.size();
    for(int i=0;i<size/2;i++){
        if(s[i] != s[size-1-i])
            return false;
    }
    return true;
}

// 暴力解决法
string longestPalindrome(string s) {
    int size = s.size();
    if(size <= 1 ) return s;
    string res = "";
    for(int i=0;i<size;i++){
        for(int j=i+1;j<=size;j++){
            string tmp = s.substr(i,j);
            if(isPalindromic(tmp) && tmp.size() > res.size()){
                res = tmp;
            }
        }
    }
    return res;
}


// DP法
string longestPalindrome_DP(string s){
    int size = s.size();
    int dp[size][size];

    int max_len = 0;
    string res = "";

    for(int i=0;i<size;i++){
        for(int j=i+1;j<=size;j++){
            int len = j-i-1;
            dp[i][j] = (len==1 || len==2 || dp[i+1][j-1]) && s[i]==s[j];
            if(dp[i][j] && len>max_len) res = s.substr(i,j);
        }
    }

    return res;
}

//string longestPalindrome_DP(string s){
//    int size = s.size();
//    int dp[size][size];
//
//    int max_len = 0;
//    string res = "";
//
//    for(int len=1;len<=size;len++){
//        for(int start=0;start<size;start++){
//            int end = start+len-1;
//            if(end >= size) break;
//            dp[start][end] = (len==1 || len==2 || dp[start+1][end-1]) && s[start]==s[end];
//            if(dp[start][end] && len>max_len) res = s.substr(start,end+1);
//        }
//    }
//
//    return res;
//}




int rob(vector<int>& nums) {
    int size = nums.size();
    if(size == 0) return 0;
    if(size == 1) return nums[0];
    if(size == 2) return max(nums[0],nums[1]);

    vector<int> dp(size+1,0);

    int max_val = 0;
    dp[0] = nums[0];
    dp[1] = nums[1]>nums[0]?nums[1]:nums[0];

    for(int i=2;i<size;i++){
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        if(dp[i]>max_val) max_val = dp[i];
    }
    return max_val;
}



int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int res = 0;
    pair<int,int> P;

    queue<pair<int,long>> mq;
    int min_val = 100000;
//    vector<int> dp(coins.size(),0);
    unordered_map<long long,int> dp;
    sort(coins.begin(),coins.end());

    for(int i=0;i<coins.size();i++){
        mq.push(make_pair(1,coins[i]));
        dp[coins[i]] = 1;
        if(coins[i] == amount) return 1;
    }

    while(!mq.empty()){
        long tmp = mq.front().second;
        int index = mq.front().first;
        mq.pop();
        for(int i=0;i<coins.size();i++){
            if(dp.find(tmp+coins[i]) == dp.end()){
                if(tmp+coins[i] > amount) break;
                if(tmp+coins[i]==amount) return index+1;
                if(tmp+coins[i]<amount){
                    mq.push(make_pair(index+1,tmp+coins[i]));
                    dp[tmp+coins[i]] = index+1;
                }
            }
        }
    }
    return -1;
}


void dfs_coin(vector<int>& coins, int amount,int cur,int cnt,int &min_val,vector<int>& dp){
    if(cur==0){
        min_val = min(cnt,min_val);
        return;
    }
    for(int i=0;i<coins.size();i++){
        if(cur-coins[i] < 0 ) break;
        dfs_coin(coins,amount,cur-coins[i],cnt+1,min_val,dp);
    }
}


int coinChange_DFS(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int min_val = 100000;

    vector<int> dp(amount+1,100000);
    sort(coins.begin(),coins.end(),greater<int> ());

    dfs_coin(coins,amount,amount,0,min_val,dp);

    return min_val!=100000?min_val:-1;
}


int coinChange_dp(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int min_val = 100000;

    vector<int> dp(amount+1,10000);
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        for(auto price:coins){
            if(i-price>=0)
                dp[i] = min(dp[i-price]+1,dp[i]);
        }
    }

    for(auto i:dp)
        cout<<i<<" ";
    cout<<endl;

    return dp[amount]!=10000?dp[amount]:-1;
}



//62.不同路径
int uniquePaths(int m, int n) {
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            if( i==0 || j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[m-1][n-1];
}



//63.不同路径II
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(!obstacleGrid.size() || !obstacleGrid[0].size()) return 0;

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    long dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0){
                if(obstacleGrid[i][j]==0) dp[i][j]=1;
                else dp[i][j]=0;
            }
            else if(i==0)  {
                if( obstacleGrid[i][j]==0) dp[i][j] = dp[i][j-1];
                else dp[i][j]=0;
            }
            else if(j==0)  {
                if( obstacleGrid[i][j]==0) dp[i][j] = dp[i-1][j];
                else dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]==1) dp[i][j]=0;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[m-1][n-1];
}



// 64. 最小路径和
int minPathSum(vector<vector<int>>& grid) {
    if(!grid.size() || !grid[0].size()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];

    for(int i=1;i<m;i++) dp[i][0] = dp[i-1][0]+grid[i][0];
    for(int i=1;i<n;i++) dp[0][i] = dp[0][i-1]+grid[0][i];

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
        }
    }
    return dp[m-1][n-1];
}





int integerBreak(int n) {
    vector<int> dp(n+1,0);
    dp[1]=1;



    for(int i=2;i<n+1;i++) {
        for(int j=i-1;j>=1;j--) {
            dp[i]=max(dp[i],dp[j]*(i-j));
            dp[i]=max(dp[i],j*(i-j));
        }
    }

    for(auto i:dp)
        cout<<i<<" ";
    cout<<endl;

    return dp[n];
}


// 474. 一和零
int findMaxForm(vector<string>& strs, int m, int n) {

    vector<vector<int>> dp(m+1,vector<int> (n+1,0));

    int size = strs.size();

    vector<vector<int>> flag(m,vector<int> (n,0));

    for(auto str:strs){
        int one = 0;
        int zero = 0;
        for(auto c:str){
            if(c=='0') zero+=1;
            else one+=1;
        }
        flag[zero][one] = 1;
    }


    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(flag[i][j] != 0){
                dp[i][j] = max(dp[i][j],dp[i][j]);
            }


        }
    }


    for(int i=0;i<size;i++){
        int one = 0;
        int zero = 0;
        for(auto c:strs[i]){
            if(c=='0') zero+=1;
            else one+=1;
        }
        for(int z=m;z>=zero;z--){
            for(int o=n;o>=one;o--){
                dp[z][o] = max(dp[z][o],dp[z-zero][o-one]+1);
            }
        }
    }

    return dp[m][n];
}


// 0-1 背包
int package_01(vector<int>& w,vector<int>& v,int c){
    int n = w.size();

    vector<vector<int>> dp(n,vector<int> (c+1,0));

    for(int i=1;i < n;i++){
        for(int j=1;j <= c;j++){
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[n-1][c-1];
}



//

string largestTimeFromDigits(vector<int>& A) {
    string res = "";
    sort(A.begin(),A.end(),greater<int> ());
    int len = A.size();
    int two = 5,five = 5;
    for(auto i:A)
        cout<<i<<" ";
    cout<<endl;

    for(int i=0;i<len;i++){
        if(A[i]<=5) five = min(i,five);
        if(A[i]<=2) two= min(i,two);
    }
    cout<<two<<" "<<five<<endl;

    for(int h=two;h<len;h++){
        for(int h2=0;h2<len;h2++){
            if((A[h]==2 && A[h2]>3) || h==h2) continue;
            for(int m=five;m<len;m++){
                if(m==h || m==h2 ) continue;
                res = to_string(A[h])+to_string(A[h2])+":"+to_string(A[m])+to_string(A[6-h-h2-m]);
                return res;
            }
        }
    }

    return "a";
}
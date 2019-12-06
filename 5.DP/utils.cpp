//
// Created by wjq on 2019/11/16.
//

#include "utils.h"


void print_vector1(string name,vector<int> v){
    cout<<name<<endl;
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

void print_vector2(string name,vector<vector<int>> v){
    cout<<name<<endl;
    for(auto x:v){
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}


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
            if(flag[i][j] != 0) {
                dp[i][j] = max(dp[i][j], dp[i][j]);
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
    return "";
}



// 416. 分割等和子集

//bool dfs_par(vector<int>& nums,float target,int index,int sum,int len,vector<int>& used){
//    if(sum==target)
//        return true;
//
//    if(index<len-1){
//        for(int i=0;i<len;i++){
//            if(used[i] == false){
//                used[i] = true;
//                if(dfs_par(nums,target,index+1,sum+nums[i],len,used))
//                    return true;
//                used[i] = false;
//            }
//        }
//    }
//
//    return false;
//}


bool dfs_par(vector<int>& nums,int target,int sum,int len,int index,vector< vector<int>> memo){
    if(sum==target) return true;
    if(memo[index][sum] == -1) memo[index][sum] = 1;

    if( index<len && target-sum < nums[index]) return false;

    for(int i=index;i<len;i++){
        if(dfs_par(nums,target,sum+nums[i],len,i+1,memo)) return true;
    }

    return false;
}

bool canPartition(vector<int>& nums) {
    if(nums.size()<=1) return false;
    if(nums.size() == 2) return nums[0]==nums[1];

    bool res = false;
    int len = nums.size();
    int sum = 0;
    for(int i:nums)
        sum+=i;
    if(sum/2!=0) return false;

//    sort(nums.begin(),nums.end(),greater<int>());

    vector< vector<int>> dp(len,vector<int>(sum/2 +1,-1));

    vector<int> used(len,0);
    res = dfs_par(nums,sum/2,0,len,0,dp);

    return res;
}




// 39
void dfs_39(vector<int> candidates, int target,int cur,vector<vector<int>>& res,vector<int>& tmp,int index){
    if(cur == target) {
        res.push_back(tmp);
        return ;
    }
    for(int i=index;i<candidates.size();++i){
        if(candidates[i]+cur <= target){
            tmp.push_back(candidates[i]);
            dfs_39(candidates,target,cur+candidates[i],res,tmp,i);
            tmp.pop_back();
        }else return ;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> tmp;
    vector<vector<int>> res;

    sort(candidates.begin(),candidates.end());
    dfs_39(candidates,target,0,res,tmp,0);
    return res;
}


// 40
void dfs_40(vector<int> candidates, int target,vector<vector<int>>& res,vector<int>& tmp,int index){
    if(target == 0) {
        res.push_back(tmp);
    }else{
        for(int i=index;i<candidates.size() && target-candidates[i] >=0 ;++i){
            //比如原数组为[1,1,2,5,6,7,10] 那么 第一个[1,7] == 第二个[1,7]
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            dfs_40(candidates,target-candidates[i],res,tmp,i+1);
            tmp.pop_back();
        }
    }
}

<<<<<<< HEAD
    return "a";
}


int findDuplicate(vector<int>& nums) {
    int slow=1,fast=1;

    while(true){
//        cout<<"fast---"<<nums[fast]<<"--"<<nums[slow]<<endl;
        fast = nums[nums[fast]];
        slow = nums[slow];
        // 找到环以后  重置fast指针,找相同的元素即为重复值
        // 这个方法不能普遍适用,存在特殊情况
        if(slow == fast) {
            fast = 0;
            while(nums[slow] != nums[fast]) {
//                cout<<"fast11---"<<nums[fast]<<"--"<<nums[slow]<<endl;
                fast = nums[fast];
                slow = nums[slow];
            }
            return nums[slow];
=======
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> tmp;
    vector<vector<int>> res;
    sort(candidates.begin(),candidates.end());
    dfs_40(candidates,target,res,tmp,0);
    return res;
}


//46 全排列
void dfs_46(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,vector<bool>& used){
    if(tmp.size()==nums.size()) res.push_back(tmp);
    else{
        for(int i=0;i<nums.size();i++){
            if(used[i] == 0){
                used[i] = 1;
                tmp.push_back(nums[i]);
                dfs_46(res,tmp,nums,used);
                tmp.pop_back();
                used[i] = 0;
            }
>>>>>>> dad826ca07db5deb6c06261e4dc7fdf46e67fbeb
        }
    }
}

<<<<<<< HEAD

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {


}

// 221 最大正方形
int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    if(row <= 0) return 0;
    int col = matrix[0].size();
    vector<vector<int>> dp (row,vector<int> (col,0));
    int max_val = 0;

    for(int i=0;i<row;i++){
        if(matrix[i][0] == '1'){
            dp[i][0] = 1;
            max_val = 1;
        }
    }

    for(int i=0;i<col;i++){
        if(matrix[0][i] == '1') {
            dp[0][i] = 1;
            max_val =1;
        }
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(matrix[i][j] == '1'){
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                max_val = max(max_val,dp[i][j]);
            }
        }
    }
    return max_val*max_val;
}



int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int size = nums.size();
    if(size == 0) return 0;
    int sum = 0,cnt=0;
    mp[0] = 1;
    for(int i=0;i<size;i++){
        sum += nums[i];
        auto iter = mp.find(sum-k);
        if(iter!=mp.end())
            cnt += iter->second;
        mp[sum]+=1;
    }

    int res = 0;
    for(int i=0;i<size;i++){
        int sum = 0;
        for(int j=i;j<size;j++){
//            cout<<"1\t"<<i<<"--"<<j<<endl;
            sum += nums[j];
            if(sum == k)
                res+=1;
        }
    }
    cout<<"cnt---"<<res<<endl;

    res = 0;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int sum = 0;
            for(int k=i;k<j+1;k++)
                sum+=nums[k];
            if(sum == k)
                res+=1;
        }
    }
    cout<<"cnt---"<<res<<endl;

    return cnt;
=======
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> used(nums.size(),0);
    int size = nums.size();
    if(size == 0) return res;
    if(size == 1) {
        res.push_back(nums);
        return res;
    }
    dfs_46(res,tmp,nums,used);
    return res;
}


//47 全排列II
void dfs_47(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,vector<bool>& used){
    if(tmp.size()==nums.size()) res.push_back(tmp);
    else{
        for(int i=0;i<nums.size();i++){
            // 当前数和之前的数一样   并且之前的数没有使用过  剪掉
            /*  1 1 1     1 1 2  1 2 1(这时之前的1使用中，说明不重复)
             *  1 1 1     1 1(之前的1没有使用过，重复）
             *  2 2 2
             */
            if(i>0 && nums[i] == nums[i-1] && used[i-1]!=0) continue;
            if(used[i]==0){
                used[i] = 1;
                tmp.push_back(nums[i]);
                dfs_47(res,tmp,nums,used);
                tmp.pop_back();
                used[i] = 0;
            }
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> used(nums.size(),0);
    int size = nums.size();
    if(size == 0) return res;
    if(size == 1) {
        res.push_back(nums);
        return res;
    }

    sort(nums.begin(),nums.end());

    dfs_47(res,tmp,nums,used);
    return res;
>>>>>>> dad826ca07db5deb6c06261e4dc7fdf46e67fbeb
}



<<<<<<< HEAD
int getMinimumDifference(TreeNode* root) {
    int min_val = INT32_MAX;
    stack<TreeNode*> ms;
    if(!root) return 0;
    TreeNode* pre=NULL,*tmp=root;
    while(!ms.empty() || tmp){

        while(tmp){
            ms.push(tmp);
            tmp = tmp->left;
        }
        if(!ms.empty()){
            if(pre)
                min_val = min(abs(ms.top()->val - pre->val),min_val);
            pre = ms.top();
            ms.pop();
            tmp = pre->right;
        }
    }
    return min_val;
}

// 216 三角形最小路径和
int minimumTotal2(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if(row==0) return 0;
    int col = triangle[row-1].size();

    vector<vector<int>> dp(row+1,vector<int> (col+1,INT32_MAX));
    dp[0][0] = triangle[0][0];

    int min_val = INT32_MAX;
    for(int i=1;i<row;i++){
        int col_ = triangle[i].size();
        for(int j=0;j<col_;j++){
            if(j==0) {
                dp[i][j] = dp[i-1][j]+triangle[i][j];
            }else if(j==col_-1){
                dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            }else{
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
    }
    for(int j=0;j<col;j++){
        min_val = min(min_val,dp[row-1][j]);
    }
    return min_val;
}


int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if(row==0) return 0;
    /*             |= triangle[n-1,c]       if n-1 is the last row.
        f(n-1, c) -|
                   |= min{f(n,c) + triangle[n-1,c], f(n,c+1) + triangle[n-1,c]}
     * */
    // 使用dp[i] 表示表示第i层所有节点的最小路径和
    // 然后从底向上  逐步更新dp[i] 最后返回dp[0] 即为第0层第一个节点的最小路径和
    vector<int> dp(row,0);
    for(int i=0;i<row;i++)
        dp[i] = triangle[row-1][i];

    for(int i=row-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
        }
    }
    return dp[0];
}



int minimumTotal_err(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if(row==0) return 0;
    /*             |= triangle[n-1,c]       if n-1 is the last row.
        f(n-1, c) -|
                   |= min{f(n,c) + triangle[n-1,c], f(n,c+1) + triangle[n-1,c]}
     * */
    // 使用dp[i] 表示表示第i层所有节点的最小路径和
    // 然后从底向上  逐步更新dp[i] 最后返回dp[0] 即为第0层第一个节点的最小路径和

    vector<int> dp(row,INT32_MAX);
    dp[0] = triangle[0][0];

    for(int i=1;i<row;i++){
        for(int j=0;j<i+1;j++){
            if(j==0) dp[j] = dp[j] + triangle[i][j];
            else if(j==i) dp[j] = dp[j-1] + triangle[i][j];
            else dp[j] = min(dp[j],dp[j-1]) + triangle[i][j];
        }
        for(int i:dp)
            cout<<i<<" ";
        cout<<endl;
    }
    for(int i:dp)
        cout<<i<<" ";
    cout<<endl;

    return *min_element(dp.begin(),dp.end());
}

/*input
     *  {{2},
        {3,4},
       {6,5,7},
      {4,1,8,3}};
如果正序遍历的话, dp[j] = dp[j],dp[j-1] , 因为计算当前层 dp[j]需要用到 上一层的dp[j-1] 和 上一层的dp[j], 但是dp[j-1]已经更新为当前层的值,
 而在计算当前层的dp[j]时,需要用到上一层的dp[j-1],但是计算当前层dp[j]前,已经更新过dp[j-1],可以从下面结果中看出

 * 2  \  \  \
 * 5  9  \  \
 * 11 14 21 \
 * 15 15 23 26
 *
 * 倒序的话,dp[j] = min(dp[j],dp[j+1]), dp[j](当前层,更新) = dp[j](上一层.未更新),dp[j+1](上一层,未更新)
 * 计算当前层dp[j] 需要用到 上一层的dp[j] 和 dp[j+1], 相当于dp[j] 更新为当前层值,dp[j+1] 等待下一个迭代更新
 *
 * */

//931. 下降路径最小和
int minFallingPathSum2(vector<vector<int>>& A) {
    int row = A.size();
    if(row == 0) return 0;
    if(row == 1) return A[0][0];
    int col = A[0].size();

    vector<vector<int>> dp(row+1,vector<int> (col+1,INT32_MAX));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0) dp[i][j] = A[i][j];
            else{
                if(j==0) dp[i][j] = min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
                else if(j==col-1) dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+A[i][j];
                else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j+1],dp[i-1][j]))+A[i][j];
            }
        }
    }
    return *min_element(dp[row-1].begin(),dp[row-1].end());
}


int minFallingPathSum3(vector<vector<int>>& A) {
    int row = A.size();
    if(row == 0) return 0;
    if(row == 1) return A[0][0];
    int col = A[0].size();

    vector<int> dp(col+1,INT32_MAX);
    vector<int> dp2(col+1,INT32_MAX);

    for(int i=row-1;i>=0;i--){
        for(int j=0;j<col;j++){
            if(i==row-1) dp[j] = A[i][j];
            else{
                if(j==0){
                    dp[j] = min(dp2[j],dp2[j+1]) + A[i][j];
                }else if(j==col-1){
                    dp[j] = min(dp2[j],dp2[j-1]) + A[i][j];
                }else{
                    dp[j] = min(dp2[j-1],min(dp2[j+1],dp2[j]))+A[i][j];
                }
            }
        }
        if(i!=0) swap(dp,dp2);
    }
    return *min_element(dp.begin(),dp.end());
}


int minFallingPathSum(vector<vector<int>>& A) {
    int row = A.size();
    if(row == 0) return 0;
    if(row == 1) return A[0][0];
    int col = A[0].size();

    vector<int> dp(col+2,INT32_MAX);
    vector<int> dp2(col+2,INT32_MAX);

    for(int i=1;i<row+1;i++){
        for(int j=1;j<col+1;j++){
            if(i==1) dp[j] = A[i-1][j-1];
            else{
                dp[j] = min(dp2[j-1],min(dp2[j+1],dp2[j]))+A[i-1][j-1];
            }
        }
        if(i!=row) swap(dp,dp2);
    }
    return *min_element(dp.begin(),dp.end());
}


//368. 最大整除子集
// 类似于最长子序列
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int size = nums.size();
    vector<int> res;
    if(size <= 1) return nums;
    vector<int> dp(size,1);
    vector<int> path(size,-1);

    sort(nums.begin(),nums.end());
    int max_len = 0,pre = -1;

    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
                path[i] = j;
            }
        }
        if(dp[i]>max_len){
            max_len = dp[i];
            pre = i;
        }
    }

    while(pre!=-1){
        res.push_back(nums[pre]);
        pre = path[pre];
    }

    reverse(res.begin(),res.end());
    return res;
}



int findLength(vector<int>& A, vector<int>& B) {

=======
//60 第k个排列  超时  应该计算大致在那个分支上  直接跳转   懒得算了
void dfs_60(vector<int>& tmp,vector<bool>& used,int& index,int k,string& res){
    if(tmp.size()==used.size()) {
        index+=1;
        if(index == k)
            for(auto i:tmp){
                res += to_string(i);
            }
    }
    else{
        for(int i=1; i<used.size()+1 && index<k;i++){
            if( used[i] == 0) {
                cout<<i<<"---index---"<<index<<endl;
                used[i] = 1;
                tmp.push_back(i);
                dfs_60(tmp, used, index, k,res);
                tmp.pop_back();
                used[i] = 0;
            }
        }
    }
}

string getPermutation(int n, int k) {
    vector<bool> used(n,0);
    vector<int> tmp;
    int index = 0;
    string res = "";
    dfs_60(tmp,used,index,k,res);
    return res;
}


// 77 zhuhe
void dfs_77(vector<vector<int>>& res,vector<int>& tmp,int index,int n,int k){
    if(tmp.size()==k) res.push_back(tmp);

    for(int i=index;i<=n;i++){
        tmp.push_back(i);
        dfs_77(res,tmp,i+1,n,k);
        tmp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;

    dfs_77(res,tmp,1,n,k);
    return res;
}


// 300
int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if(size<=1) return size;
    vector<int> dp(size,1);
    int max_val = 1;
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
                max_val = max(max_val,dp[i]);
            }
        }
    }
    return max_val;
}



int findNumberOfLIS(vector<int>& nums) {
    int size = nums.size();
    if(size<=1) return size;
    vector<int> dp(size,1);
    vector<int> tmp(size,1);

    int max_val = 1;
    /* vector<int> cc{1,2,4,3,5,4,7,2};   最长5
     *  dp = 1 2 3 3 4 4 5 2
     *  tmp = 1 1 1 1 2 1 3 1
     * */
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(dp[j]+1>dp[i]){ // 如果更长的序列，则更新序列，不更新组合长度
                    dp[i] = dp[j]+1;
                    tmp[i] = tmp[j];
                }else if(dp[j]+1==dp[i]) // 如果有别的路径走到这个长度，组合长度累加
                    tmp[i] += tmp[j];
            }
            max_val = max(max_val,dp[i]);
        }
    }

    cout<<"max_val"<<max_val<<endl;
    print_vector1("dp---",dp);
    print_vector1("tmp---",tmp);

    int res = 0;
    for(int i =0;i<size;i++){
        if(dp[i]==max_val)
            res+=tmp[i];
    }

    return res;
>>>>>>> dad826ca07db5deb6c06261e4dc7fdf46e67fbeb
}
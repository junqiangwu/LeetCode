//
// Created by wjq on 2019/11/28.
//

#include "utils.h"


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.push_back({});
    int size=nums.size();
    // 每一位有两个状态 取与不取 即2^n次方个状态  123 对应 000-111 共八个状态
    int subsize=pow(2,size);
    int hash=1;
    while(hash<subsize){
        vector<int> temp;
        for(int k=0;k<size;k++) {
            // 使用a左移 判断当前状态hash每一位是否为1,1则加入当前自分组 nums.size=k 所以需要移动k次
            // 123  001  010  100 分别和hash & 判断当前元素是否添加到子数组中
            int a=1<<k;
            if(a&hash) {
                temp.push_back(nums[k]);
            }
        }
        ret.push_back(temp);
        hash++;
    }
    return ret;
}




// 79 单词搜索   BFS 有bug  如果一个字母旁边的三个字符都可以使用的话  BFS就会只取其1
bool find(vector<vector<char>>& board, string word,int i,int j,int dep){

    queue<pair<int,int>> mq;

    int row = board.size();
    int col = board[0].size();
    mq.push(make_pair(i,j));
    vector<vector<int>> tmp(row,vector<int> (col,0));
    tmp[i][j] = 1;
    int dx[4] = {0,0,-1,+1};
    int dy[4] = {-1,+1,0,0};
    while(!mq.empty()){
        int i = mq.front().first;
        int j = mq.front().second;
        mq.pop();
        bool flag = false;
        for(int k=0;k<4;k++){
            int new_x = i+dx[k];
            int new_y = j+dy[k];
            if(new_x>=0 && new_y>=0 && new_x<row && new_y<col && !tmp[new_x][new_y] &&board[new_x][new_y] == word[dep]){
                tmp[new_x][new_y] = 1;
                mq.push(make_pair(new_x,new_y));
                flag = true;
            }
        }
        if(flag==true && dep < word.size()-1) dep+=1;
        if(flag==true || dep == word.size()) return true;
    }
    return false;
}

bool find_d(vector<vector<char>>& board, string word,int i,int j,int dep,vector<vector<int>>& tmp){
    if(dep == word.size()) return true;
    int row = board.size();
    int col = board[0].size();

    int dx[4] = {0,0,-1,+1};
    int dy[4] = {-1,+1,0,0};

    for(int k=0;k<4;k++){
        int new_x = i+dx[k];
        int new_y = j+dy[k];
        if(new_x>=0 && new_y>=0 && new_x<row && new_y<col && !tmp[new_x][new_y] && board[new_x][new_y] == word[dep]){
            tmp[new_x][new_y] = 1;
            if(find_d(board,word,new_x,new_y,dep+1,tmp)) return true;
            tmp[new_x][new_y] = 0;
        }
    }
    return false;
}

// 79 单词搜索
bool exist(vector<vector<char>>& board, string word) {
    int size_w = word.size();
    int row = board.size();
    if(row == 0 && size_w == 0) return true;
    if(row == 0 && size_w != 0) return false;

    int col = board[0].size();

    queue<char> mq;
    vector<vector<int>> tmp(row,vector<int> (col,0));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j] == word[0]){
                tmp[i][j] = 1;
                bool res = find_d(board,word,i,j,1,tmp);
                tmp[i][j] = 0;
                if(res) return true;
            }
        }
    }
    return false;
}

int cnt = 0;
bool fnid_416(vector<int>& nums,vector<int>& flag,int target,int index){
    cnt+=1;
    cout<<"11---"<<cnt<<endl;
    if(target == 0) return true;

    for(int i=index;i<nums.size();i++){
        if(nums[i] > target || flag[i]) continue;
        flag[i] = 1;
        if(fnid_416(nums,flag,target-nums[i],i+1)) return true;
        flag[i] = 0;
    }
    return false;
}


// 416
bool canPartition(vector<int>& nums) {
    int sum = 0;
    int size = nums.size();
    if(size <= 1) return false;
    for (int i:nums) sum+=i;
    cout<<"sum---"<<sum<<endl;
    if( sum%2 != 0) return false;
    int target = sum/2;
    vector<int> flag(size,0);

    sort(nums.begin(),nums.end(),greater<int>());

    bool res = fnid_416(nums,flag,target,0);
    return res;
}




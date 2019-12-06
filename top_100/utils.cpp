//
// Created by wjq on 2019/11/27.
//

#include "utils.h"

void print_vector2(string name,vector<vector<int>> v){
    cout<<name<<endl;
    for(auto x:v){
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}

void print_vector1(string name,vector<int> v){
    cout<<name<<endl;
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n / 2; i++) matrix[i].swap(matrix[n - 1 - i]);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> res;
    if(size == 0){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    int l=0,h=size-1;
    while(l<=h){
        int mid = (h-l)/2+l;
        if(nums[mid] > target)
            h = mid-1;
        else if(nums[mid] < target)
            l = mid+1;
        else{
            int tmp_l=mid,tmp_h=mid;
            while(tmp_l>=1 && nums[tmp_l-1]==target){
                tmp_l-=1;
            }
            while(tmp_h+1<size && nums[tmp_h+1]==target){
                tmp_h+=1;
            }
            res.push_back(tmp_l);
            res.push_back(tmp_h);
            break ;
        }
    }

    if(res.size()==0){
        res.push_back(-1);
        res.push_back(-1);
    }
    return res;
}



vector<vector<int>> subsets(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> res;
    if(size <= 1){
        res.push_back(nums);
        return res;
    }

    for(int len=1;len<=size;len++){
        for(int i=0;i+len<size;i++){
            vector<int> tmp;
            for(int k=i;k<=i+len;k++){
                tmp.push_back(nums[k]);
            }
            res.push_back(tmp);
        }
    }

    return res;
}
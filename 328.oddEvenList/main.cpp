#include <iostream>
#include <vector>
#include <stack>
#include "Solution.h"
#include <ctime>
#include <map>

using namespace std;

// 75. 三色排序问题
void sortColors(vector<int>& nums) {
    int l=0,lt=0,gt=nums.size();

    for(int i=0;i<nums.size() && lt<=gt;i++){
        if(nums[i]==0){
            swap(nums[i],nums[l]);
            l++;
            lt++;
        }else if(nums[i]==1){
            lt++;
        }else if(nums[i]==2){
            swap(nums[i],nums[gt]);
            gt--;
            --i;
        }

    }
}

int main() {
//    vector<int> v = {6,6,6,1,2,3,6,4,5,6};
    vector<int> a = {1,1,2,1,2,1,2,0,1,2,0};
    vector<int> v = {1,2,3,4};
    Solution solution;

    ListNode* head = solution.Creat_List(v);

//    ListNode* tmp = Solution().Remove_Elem(head,6,1);

//    ListNode* tmp = Solution().Rerverse_List(head,2);

//    ListNode* tmp = Solution().oddEvenList(head);

//    ListNode* tmp = solution.insertionSortList(head);

//    ListNode* tmp = solution.sortList_v2(head);

    solution.reorderList(head);

//    Solution().Print_List(res);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
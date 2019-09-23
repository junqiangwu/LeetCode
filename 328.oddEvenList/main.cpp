#include <iostream>
#include <vector>
#include <stack>
#include "Solution.h"
#include <ctime>

using namespace std;


void merge_sort(vector<int>& v){
    


}



int main() {
//    vector<int> v = {6,6,6,1,2,3,6,4,5,6};
    vector<int> v = {1,3,5,2,8,7,6,4};
    Solution solution;

    ListNode* head = solution.Creat_List(v);

//    ListNode* tmp = Solution().Remove_Elem(head,6,1);

//    ListNode* tmp = Solution().Rerverse_List(head,2);

//    ListNode* tmp = Solution().oddEvenList(head);

//    ListNode* tmp = solution.insertionSortList(head);

    ListNode* tmp = solution.sortList_v2(head);
    Solution().Print_List(tmp);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
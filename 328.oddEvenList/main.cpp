#include <iostream>
#include <vector>
#include <stack>
#include "Solution.h"
#include <ctime>
#include <map>
#include <string>

using namespace std;

int main() {
//    vector<int> v = {6,6,6,1,2,3,6,4,5,6};
    vector<int> a = {1,1,2,1,2,1,2,0,1,2,0};
    vector<int> v = {1,2,3,4,5};
    vector<int> c = {10,9,8,7};
    vector<int> d = {5,6,7,8};

    Solution solution;

    ListNode* head = solution.Creat_List(v);

//    ListNode* tmp = Solution().Remove_Elem(head,6,1);

//    ListNode* tmp = Solution().Rerverse_List(head,2);

//    ListNode* tmp = Solution().oddEvenList(head);

//    ListNode* tmp = solution.insertionSortList(head);

//    ListNode* tmp = solution.sortList_v2(head);

    solution.reorderList(head);

    Solution().Print_List(head);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
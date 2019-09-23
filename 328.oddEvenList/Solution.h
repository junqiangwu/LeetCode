//
// Created by wjq on 2019/9/23.
//

#ifndef INC_328_ODDEVENLIST_SOLUTION_H
#define INC_328_ODDEVENLIST_SOLUTION_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};


class Solution{
public:
    // 147
    ListNode* insertionSortList(ListNode* head);
    // 148
    ListNode* sortList(ListNode* head);
    ListNode* sortList_v2(ListNode* head);

    ListNode* middleNode(ListNode* head);

    ListNode* oddEvenList(ListNode* head);

    ListNode* Rerverse_List(ListNode* head,int flag);

    ListNode* Remove_Elem(ListNode* head,int target,int flag);

    ListNode* Remove_Elem_Stack(ListNode* head,int target);

    ListNode* Creat_List(vector<int> v);

    void Print_List(ListNode* head){
        if(head==NULL)
            printf("NULL");
        ListNode* tmp = head;
        while(tmp!=nullptr){
            cout<<tmp->val<<"-->";
            tmp = tmp->next;
        }
        cout<<"NULL"<<endl;
    }

};


#endif //INC_328_ODDEVENLIST_SOLUTION_H

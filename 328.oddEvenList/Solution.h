//
// Created by wjq on 2019/9/23.
//

#ifndef INC_328_ODDEVENLIST_SOLUTION_H
#define INC_328_ODDEVENLIST_SOLUTION_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};


class Solution{
public:
    // 143.重排链表
    void reorderList(ListNode* head);
    // //86. 分割链表   注意两个链表的头指针
    ListNode* partition(ListNode* head, int x);
    //725. 分隔链表
    vector<ListNode*> splitListToParts(ListNode* root, int k);

    //1171. 从链表中删去总和值为零的连续节点
    ListNode* removeZeroSumSublists(ListNode* head);

    // 1019. 链表中的下一个更大节点
    vector<int> nextLargerNodes(ListNode* head);

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

#include <iostream>


using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

         ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
         ListNode* dump = tmp;

        while(l1!=NULL && l2!= NULL){
            if(l1->val <= l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }

        tmp->next = l1?l1:l2;
        // if(l1!=NULL){
        //     tmp->next = l1;
        // }
        // if(l2!=NULL){
        //     tmp->next = l2;
        // }
        return dump->next;
    }
};

int main() {
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l4 = ListNode(4);
    l1.next = &l2;
    l2.next = &l4;

    ListNode r1 = ListNode(1);
    ListNode r3 = ListNode(3);
    ListNode r4 = ListNode(4);
    r1.next = &r3;
    r3.next = &r4;

    ListNode* ret = Solution().mergeTwoLists(&l1,&r1);

    while (ret!=NULL){

        printf("%d",ret->val);
        ret = ret->next;
    }

    return 0;
}
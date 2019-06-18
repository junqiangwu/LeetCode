#include <iostream>

#include <vector>


struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;


class Solution {

public:

    ListNode* swapPairs(ListNode* head) {

        if (head != NULL && head->next != NULL)
        {
            ListNode *temp = head->next;
            head->next = swapPairs(head->next->next);
            temp->next = head;
            head = temp;
        }
        return head;
    }

    ListNode* swapPairs2(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != NULL && cur->next->next !=NULL){
            ListNode* node1 = cur->next;
            ListNode* node2 = node1->next;
            ListNode* rear = node2->next;
            cur->next = node2;
            node2->next = node1;
            node1->next = rear;
            cur = node1;
        }
        return dummyHead->next;
    }

    ListNode* Creat_list(vector<int> node) {
        ListNode* head = NULL,*tmp = NULL;

        int len = node.size();

        for(int i=0;i<len;i++){
            if (i==0){
                head = new ListNode(node[i]);
                head->next=NULL;
                tmp = head;
            }else{
                ListNode* new_op = new ListNode(node[i]);
                new_op->next = NULL;
                tmp->next = new_op;
                tmp = tmp->next;
            }

        }
        return head;
    }

};





int main() {
    vector<int> v = {1,2,3,4,5,6};
    ListNode *head = Solution().Creat_list(v);
    ListNode *tmp = head;

    while (tmp!=NULL){

        printf("%d",tmp->val);
        tmp = tmp->next;
    }
    cout<<endl;

    ListNode* ret = Solution().swapPairs2(head);

    while (ret!=NULL){

        printf("%d",ret->val);
        ret = ret->next;
    }

    return 0;
}
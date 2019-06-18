#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* pre = head;
        int len=0;
        while(pre!=NULL){
            pre = pre->next;
            len+=1;
        }
        int cnt = k%len;
        if(cnt==0) return head;

        pre = head;
        ListNode* cur = head;

        while(cur!=NULL){
            if(cnt--<0) pre = pre->next;
            cur = cur->next;
        }

        cur = pre->next;
        ListNode* tmp = cur;
        pre->next = NULL;

        for(int i=1;i< k%len ;i++){
            cur = cur->next;
            printf("%d: %d \n",i,cur->val);
        }
        cur->next = head;

        return tmp;
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
    vector<int> v = {1,2,3,4,5};
    ListNode *head = Solution().Creat_list(v);

    ListNode* ret = Solution().rotateRight(head,2);

    while (ret!=NULL){
        printf("%d",ret->val);
        ret = ret->next;
    }
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
// 递归算法
class Solution {
public:

  ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;

        ListNode* pre = new ListNode(0);
        pre->next = head;

        ListNode* tmp = pre;
        int len = 0;
        while(tmp!=NULL){
            tmp = tmp->next;
            len++;
        }
        if(len-n==1)
            return head->next;

        for(int i=1;i<len-n;i++){
            pre = pre->next;
        }

        pre->next = pre->next->next;
        return head;
    }
    // 1. 先计算list长度，然后定位倒数第n个节点的位置

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        if (!head)
            return head;
        ListNode* tmp = head;
        int len = 0;
        while(tmp!=NULL){
            tmp = tmp->next;
            len+=1;
        }
        tmp = head;
        int index = len-n-1;
        //定位需要移除节点的父节点，如果不存在父节点
        // 说明移除的是头结点，直接返回 head->next
        if (index<0)
            return head->next;

        for(int i=1;i<=index;i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }

    //2. 利用 前后 两个节点，节点索引差值为n，所以当 后节点 为尾节点时，前节点为要移除节点

    ListNode* removeNthFromEnd3(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* p = dummy;
        while (cur) {
            if (n-- < 0) {
                p = p->next;
            }
            cur = cur->next;
        }
        p->next = p->next->next;
        return dummy->next;
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
    vector<int> v = {1,2};
    ListNode *head = Solution().Creat_list(v);

    ListNode* ret = Solution().removeNthFromEnd(head,2);

    while (ret!=NULL){
        printf("%d",ret->val);
        ret = ret->next;
    }
    return 0;
}

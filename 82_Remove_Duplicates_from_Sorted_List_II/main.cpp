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

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p= head->next, *pre=head, *ppre = dummy;
        while(p){
            if(p->val == pre->val){
                pre= p;
                p=p->next;
            }
            else if(ppre->next != pre){
                ppre->next = p;
                pre =p;
                p= p->next;
            }
            else{
                ppre = pre;
                pre =p;
                p=p->next;
            }
        }
        if(ppre->next != pre)
            ppre->next =p;
        return dummy->next;
    }

    ListNode* deleteDuplicates3(ListNode* head) {
        ListNode* ptr = head, *pptr = NULL;
        while(ptr && ptr->next){
            if(ptr->val == ptr->next->val){
                // 头结点特殊处理  直接后移
                while(ptr && ptr->next && ptr->val == ptr->next->val){
                    ptr = ptr->next;
                }
                if(pptr == NULL){
                    head = ptr->next;
                    ptr = ptr->next;
                    pptr = NULL;
                }  else {
                    pptr->next = ptr->next;
                    ptr = pptr;
                }
            } else {
                pptr = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }

    // 可以借用set 记录下重复数字 然后使用两个指针节点 进行跳接
    ListNode* deleteDuplicates5(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        vector<int> s;

        ListNode* tmp = head;
        int val;
        while(tmp!=NULL && tmp->next!=NULL){

            if (tmp->val == tmp->next->val && tmp->val != val ) {
                s.push_back(tmp->val);
                val = tmp->val;
            }

            tmp = tmp->next;
        }

        std::cout<<s.size()<<endl;
        int len = s.size();

        tmp = head;
        ListNode* ptr = NULL;
        int flag=0;

        while(tmp!=NULL){
            // 最坏情况  全部重复  n2复杂度
            for(int i=0;i<len;i++){
                if (tmp->val == s[i]) {
                    flag=1;
                }
            }

            if(flag==1){
                // ptr==NULL  说明头结点为重复节点，直接next 头结点
                if (ptr != NULL) {
                    ptr->next = tmp->next;
                } else {
                    head = tmp->next;
                }
            }else{
                // 如果tmp节点为重复节点  则只移动tmp节点即可  不需要后移ptr节点
                ptr = tmp;
            }
            flag = 0;
            tmp = tmp->next;
        }
        return head;
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
    vector<int> v = {1,1,1,2,3};
    ListNode *head = Solution().Creat_list(v);

    ListNode* ret = Solution().deleteDuplicates3(head);

    while (ret!=NULL){
        printf("%d ++",ret->val);
        ret = ret->next;
    }


    return 0;
}

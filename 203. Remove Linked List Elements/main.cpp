#include <vector>
#include <iostream>
#include <time.h>
#include <ctime>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

//    ListNode *detectCycle(ListNode *head) {
//        if (!head) return NULL;
//        map<ListNode*,int> m;
//
//        ListNode* slow = head;
//        ListNode* fast = head;
//
//        int index = 0;
//        while(fast && fast->next){
//            m[slow] = index;
//
//            if(slow == fast){
//                int tmp = m.find(head);
//                return tmp;
//            }
//            slow = slow->next;
//            fast = fast->next->next;
//            index+=1;
//
//        }
//    }

    // 递归实现
    ListNode* removeElements(ListNode* head, int val) {
            if(head == NULL) return head;
            ListNode* nextNode = removeElements(head->next, val);
            if(head->val == val) return nextNode;
            else {
                head->next = nextNode;
                return head;
            }
     }

    // 非递归  提前处理头结点
    ListNode* removeElements_2(ListNode* head, int val) {
        if (!head) return head;
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        ListNode *ptr = NULL;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) ptr->next = cur->next;
            else {
                ptr = cur;
            }
            cur = cur->next;
        }
        return head;
    }

    // 非递归  中间处理头结点
    ListNode* removeElements_3(ListNode* head, int val) {
        if (!head) return head;
        ListNode *ptr = NULL;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) {
                if (!ptr) {
                    head = head->next;
                    cur = head;
                    continue;
                } else {
                    ptr->next = cur->next;
                    cur = cur->next;
                }
            } else {
                ptr = cur;
                cur = cur->next;
            }

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
    clock_t startTime,endTime;

    vector<int> v = {6,6,1,2,6,3,4,6,5};
    ListNode *head = Solution().Creat_list(v);

    startTime = clock();//计时

    ListNode* ret = Solution().removeElements(head,6);

    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时

    ListNode* ret2 = Solution().removeElements_2(head,6);

    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;



    while (ret!=NULL){
        printf("%d",ret->val);
        ret = ret->next;
    }
    return 0;
}



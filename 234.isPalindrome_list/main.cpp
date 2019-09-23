#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

    ListNode* reverse(ListNode* head){
        if (head->next == nullptr)
            return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head==nullptr || head->next == nullptr)
            return true;
        ListNode* fast=head,*slow = head,*prev=nullptr;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("%c -- %c",fast->val,slow->val);

//        while (slow){//reverse
//            ListNode* ovn = slow->next;
//            slow->next = prev;
//            prev = slow;
//            slow = ovn;
//        }

        prev = reverse(slow->next);


        ListNode* tmp = prev;
        while(tmp!=NULL){
            printf("++ %c",tmp->val);
            tmp = tmp->next;
        }
        while(prev!=nullptr){
            if(prev->val != head->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }

    void del_List(ListNode* head){

        while(head!=NULL){
            ListNode* delNode = head;
            head = head->next;

            delete delNode;

        }
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
    vector<int> v = {'a','b','c','d','e','d','c','b','a'};
    ListNode *head = Solution().Creat_list(v);

//    bool a = Solution().isPalindrome(head);
//    cout << a <<endl;

    Solution().del_List(head);
    cout<<111<<endl;

    while (head!=NULL){
        printf("%c ++",head->val);
        head = head->next;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
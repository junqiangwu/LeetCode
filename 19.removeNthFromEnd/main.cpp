#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x) ,next(NULL) {}
};


class Sloution{

public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *p = new ListNode(0);
        p= head;
        ListNode *q = new ListNode(0);
        q= head;

        for(int i=0;i<n;i++){
            if (p)
                p = p->next;
            else
                return head;
        }
        if(p==nullptr)
            return head->next;

        while(p->next!=nullptr){
            p = p->next;
            q = q->next;
        }

        q->next = q->next->next;

        return head;
    }

    ListNode* Creat_List(vector<int> v){
        ListNode* head = new ListNode(v[0]);
        ListNode* pre = head;
        for(int i=1;i<v.size();i++){
            ListNode* tmp = new ListNode(v[i]);
            pre->next = tmp;
            pre = tmp;
        }

        return head;
    }

    void Print_List(ListNode* head){

        while(head!=NULL){
            cout<<head->val;
            cout<<"-->";
            head = head->next;
        }
        cout<<"NULL"<<endl;
    }

    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;

        while(head!=nullptr){
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy,*cur = pre;
        int num =0;
//        while(cur = cur->next) ++num;
        while(cur){
            cur = cur->next;
            num++;
        }

        cout<<num<<endl;

        for(int i=0;i<num/k;i++){
            cur = pre->next;
            for(int j=1;j<k;j++){
                ListNode* t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
        }

        return dummy->next;
    }

};




int main() {
    vector<int> v = {1,2,3,4,5,7,8};
    ListNode* head = Sloution().Creat_List(v);
    Sloution().Print_List(head);

    ListNode* head2 = Sloution().reverseKGroup(head,3);
    Sloution().Print_List(head2);

//    ListNode* head2 = Sloution().reverse(head);
//    Sloution().Print_List(head2);
//
//    ListNode* res = Sloution().removeNthFromEnd(head,6);
//    Sloution().Print_List(res);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
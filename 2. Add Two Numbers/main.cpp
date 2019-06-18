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
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> ret_val;

        int cnt=0;

        while(l1!=NULL && l2!=NULL){
            int tmp = l1->val + l2->val;
            l1 =l1->next;
            l2 =l2->next;
            ret_val.push_back(tmp%10);
            cnt+=1;

            if (tmp>9){
                int index = cnt-1;
                for(;;){
                    if (index==0){
                        ret_val.insert(ret_val.begin(),1);
                        break;
                    }else{
                        index-=1;
                        if (ret_val[index]>=9){
                            ret_val[index]=0;
                        }else{
                            ret_val[index]+=1;
                            break;
                        }
                    }

                }
            }

        }
            for(;l1!=NULL;l1=l1->next){
                ret_val.push_back(l1->val);
            }

            for(;l2!=NULL;l2=l2->next){
                ret_val.push_back(l2->val);
            }

        ListNode* tmp = new ListNode(0);
        ListNode* dump = tmp;
        int len = ret_val.size();

        dump->val = ret_val[len-1];

        for(int i=len-2;i>=0;i--){
            dump->next = new ListNode(ret_val[i]);
            dump = dump->next;
        }

        return tmp;
    }*/

    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode *result = nullptr, *temp = nullptr, *prev = nullptr;
        while(a or b){
            int sum = carry + (a ? a->val : 0) + (b ? b->val : 0);
            carry = sum >= 10;
            sum %= 10;
            temp = new ListNode(sum);
            if(!prev) result = temp;
            else prev->next = temp;
            prev = temp;
            a = a ? a->next : nullptr;
            b = b ? b->next : nullptr;
        }
        if(carry) temp->next = new ListNode(carry);
        return result;
    }

};


int



int main() {
    ListNode *a = new ListNode(2);

    a->next = new ListNode(4);

//    a->next = new ListNode(3);

    ListNode *b = new ListNode(5);
    b->next = new ListNode(6);
//    b->next = new ListNode(4);

    ListNode* ret = Solution().addTwoNumbers(a,b);

    while(ret!=NULL){
        std::cout <<ret->val<< std::endl;
        ret = ret->next;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
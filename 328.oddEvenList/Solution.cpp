#include "Solution.h"

//
// Created by wjq on 2019/9/23.
//

//143. 重排链表
void Solution::reorderList(ListNode* head){
    if (head==nullptr || head->next==nullptr) return;
    ListNode* fast = head,*slow = head;
    ListNode* pre;
    while(fast && fast->next){
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    pre->next = nullptr;
    ListNode* pre2 = nullptr;
    while(slow!=nullptr){
        ListNode* tmp = slow->next;
        slow->next = pre2;
        pre2 = slow;
        slow = tmp;
    }
    pre = head;
    while(pre->next && pre2->next){
        ListNode* tmp = pre->next;
        ListNode* tmp2 = pre2->next;
        pre->next = pre2;
        pre2->next = tmp;
        pre = tmp;
        pre2 = tmp2;
    }
    if(!pre->next)  pre->next = pre2;
    if(!pre2->next) pre2->next = pre;

    Solution().Print_List(head);
}


//86. 分割链表   注意两个链表的头指针
ListNode* Solution::partition(ListNode* head, int x) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* node_s = dummy,*node_d = dummy;
    ListNode* pre_d = node_d,*pre_s=node_s;

    while(head!= nullptr){
        if(head->val >= x){
            node_d->next = head;
            node_d = head;
            if(pre_d==dummy) pre_d = node_d;
        }else{
            node_s->next = head;
            node_s = head;
            if(pre_s==dummy) pre_s=node_s;
        }
        head = head->next;
    }
    node_d->next = nullptr;
    pre_d = pre_d==dummy?pre_d->next:pre_d;
    node_s->next = pre_d;
    pre_s = pre_s==dummy?pre_s->next:pre_s;
    return pre_s;
}


// 725. 分隔链表
ListNode* cut2(ListNode* head,int k){
    ListNode* tmp = head;
    while(--k && tmp){
        tmp = tmp->next;
    }
    if(tmp==nullptr) return nullptr;

    ListNode* tmp2 = tmp->next;
    tmp->next = nullptr;
    return tmp2;
}

vector<ListNode*> Solution::splitListToParts(ListNode* root, int k) {
    int len=0;
    vector<ListNode*> res;
    vector<int> cut_s;
    ListNode* pre = root;
    while(pre!=nullptr){
        ++len;
        pre = pre->next;
    }
    ListNode* cur = root;
    int len_y = len%k;
    for(int i=0;i<k;i++){
        if(i<len_y){
            res.push_back(cur);
            cur = cut2(cur,len/k+1);
        }
        else {
            res.push_back(cur);
            cur = cut2(cur, len / k);
        }
    }
    return res;
}

//1171. 从链表中删去总和值为零的连续节点
ListNode* Solution::removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* p=dummy;
    while(p){
        ListNode* tmp = p->next;
        int sum=0;
        while(tmp){
            sum+=tmp->val;
            if(sum==0)
                break;
            tmp = tmp->next;
        }
        if(tmp==nullptr){
            p = p->next;
        }else{
            p->next = tmp->next;
        }
    }
    return dummy->next;
}

// 1019. 链表中的下一个更大节点
vector<int> Solution::nextLargerNodes(ListNode* head) {
    vector<int> res;
    if(head== nullptr) return res;
    stack<ListNode*> ms;
    map<ListNode*,int> mm;
    ListNode* tmp = head;
    ms.push(head);

    while(!ms.empty() && head->next!=nullptr){
        if(head->next->val > ms.top()->val){
            while( !ms.empty() && head->next->val > ms.top()->val) {
                mm[ms.top()] = head->next->val;
                ms.pop();
            }
        }
        ms.push(head->next);
        head = head->next;
    }

    cout<<111<<endl;
    while(tmp!= nullptr){
        if(mm.find(tmp)!=mm.end()){
            res.push_back(mm[tmp]);
        }else{
            res.push_back(0);
        }
        tmp = tmp->next;
    }

    return res;
}


// 147. 对链表进行插入排序
ListNode* Solution::insertionSortList(ListNode* head){
    if(head== nullptr || head->next == nullptr) return head;
    ListNode* dummy = new ListNode(0),*pre;
    dummy->next = head;

    while(head!= nullptr && head->next!=nullptr) {
        if (head->val < head->next->val) {
            head = head->next;
            continue;
        }
        pre = dummy;
        while (pre->next->val < head->next->val)
            pre = pre->next;
        ListNode* cur_n = head->next;
        head->next = cur_n->next;
        cur_n->next = pre->next;
        pre->next = cur_n;
    }
    return dummy->next;
}


// 148. 排序链表

ListNode* cut(ListNode* head,int n){
    ListNode* tmp = head;
    while(--n && tmp){
        tmp =tmp->next;
    }
    if(!tmp) return nullptr;

    ListNode* next = tmp->next;
    tmp->next = nullptr;
    return next;
}

ListNode* merge(ListNode* l1,ListNode* l2){
    ListNode* pre = new ListNode(0);
    ListNode* tmp = pre;
    while(l1 && l2){
        if(l1->val > l2->val){
            tmp->next = l2;
            tmp = l2;
            l2 = l2->next;
        }else{
            tmp->next = l1;
            tmp = l1;
            l1 = l1->next;
        }
    }
    tmp->next = l1?l1:l2;
    return pre->next;
}


ListNode* Solution::sortList(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int lenght = 0;
    auto p = head;
    while(p){
        lenght+=1;
        p = p->next;
    }
    for(int size=1 ;size<lenght ;size *= 2){
        ListNode* cur = dummy->next;
        ListNode* tail = dummy;

        while(cur){
            ListNode* left = cur;
            ListNode* right = cut(left,size);
            cur = cut(right,size);
            tail->next = merge(left,right);
            while(tail->next)
                tail = tail->next;
        }
    }

    return dummy->next;
}


ListNode* Merge_Sort(ListNode* head){
    if(!head->next) return head;

    ListNode* fast=head,*slow = head;
    ListNode* pre = nullptr;
    while(fast && fast->next){
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    pre->next = nullptr;
    ListNode* l = Merge_Sort(head);
    ListNode* r = Merge_Sort(slow);
    return merge(l,r);
}

ListNode* Solution::sortList_v2(ListNode* head){
    return Merge_Sort(head);
}



ListNode* Solution::middleNode(ListNode* head) {
    ListNode* fast=head,*slow=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* Solution::oddEvenList(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // head 为奇链表头结点，o 为奇链表尾节点
    ListNode* o = head;
    // p 为偶链表头结点  e 为欧链表尾节点  每次都跳两步
    ListNode* p = head->next,*e = p;
    while(o->next!= nullptr && e->next!= nullptr){
        o->next = o->next->next;
        o = o->next;
        e->next = e->next->next;
        e = e->next;
    }
    o->next = p;
    return head;
}

ListNode* Solution::Rerverse_List(ListNode* head,int flag){
    if (flag==0){
        // 递归找尾节点
        if(head->next==nullptr) return head;
        ListNode* nextNode = Rerverse_List(head->next,0);
        head->next->next = head;
        head->next = nullptr;
        return nextNode;
    }
    else if(flag==1){
        // 三指针
        ListNode* pre = nullptr;
        while(head!= nullptr){
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }else{
        // 原链表头删  反转链表头插
        ListNode* newHead = nullptr;
        ListNode* node = head;
        while(head!= nullptr){
            node = head;
            head = head->next;
            node->next = newHead;
            newHead = node;
        }
        return newHead;
    }
}

ListNode* Solution::Remove_Elem(ListNode* head,int target,int flag){
    if(flag==0){
        // 递归到链表的尾节点，然后逐个弹出，如果当前节点==val 则弹出上一个节点
        if(!head) return head;
        ListNode* nextNode = Remove_Elem(head->next,target,0);
        if(head->val==target) {
            return nextNode;
        }else{
            head->next = nextNode;
            return head;
        }
    }else{
        // 建立虚拟头结点  避免对头结点进行特俗处理
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(head!= nullptr){
            if(head->val == target)
                pre->next = head->next;
            else
                pre = head;
            head = head->next;
        }
        return dummy->next;
    }
}

ListNode* Solution::Remove_Elem_Stack(ListNode* head,int target){
    stack<ListNode*> my_s;
    ListNode* tmp = head;
    while(tmp!=nullptr){
        my_s.push(tmp);
        tmp = tmp->next;
    }

    // 处理头结点
    tmp = my_s.top();
    my_s.pop();
    for(;tmp->val == target;){
        tmp = my_s.top();
        tmp->next = NULL;
        my_s.pop();
    }

    while(!my_s.empty()){

        ListNode* nextNode = my_s.top();
        my_s.pop();
        if(nextNode->val==target){
            continue;
        }else{
            nextNode->next = tmp;
            tmp = nextNode;
        }
    }
    return tmp;
}

ListNode* Solution::Creat_List(vector<int> v){
    if (v.size()==0) return NULL;

    ListNode* head = new ListNode(v[0]);
    ListNode* tmp = head;
    for(int i=1;i<v.size();i++){
        ListNode* node = new ListNode(v[i]);
        tmp->next = node;
        tmp = tmp->next;
    }
    return head;
}


#include "Solution.h"

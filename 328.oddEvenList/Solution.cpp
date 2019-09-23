#include "Solution.h"

//
// Created by wjq on 2019/9/23.
//

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

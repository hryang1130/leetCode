//
// Created by kevin on 2023/6/11.
//

#ifndef LEETCODEGITHUB_1171_HPP
#define LEETCODEGITHUB_1171_HPP
//https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
#include <map>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        //头节点
        ListNode* res = new ListNode(0,head);
        map<int,ListNode*> sums;
        int s=0;
        ListNode* cur = res;
        while(cur){
            s+=cur->val;
            sums[s]=cur;
            cur=cur->next;
        }
        s=0;
        cur = res;
        while(cur){
            s+=cur->val;
            cur->next=sums[s]->next;
            cur=cur->next;
        }

        return res->next;
    }
};

#endif //LEETCODEGITHUB_1171_H

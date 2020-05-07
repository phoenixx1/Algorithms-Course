/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

https://leetcode.com/problems/merge-two-sorted-lists/
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head = NULL;
        ListNode *t1 = l1, *t2 = l2;
        if(t1->val <= t2->val){
            head = t1;
            t1 = t1->next;
        }else{
            head = t2;
            t2 = t2->next;
        }
        ListNode *newHead = head;
        while(t1 != NULL && t2 != NULL){
            if(t1->val <= t2->val){
                newHead->next = t1;
                newHead = newHead->next;
                t1 = t1->next;
            }else{
                newHead->next = t2;
                newHead = newHead->next;
                t2 = t2->next;
            }
        }
        if(t1 != NULL){
            newHead->next = t1;
        }else{
            newHead->next = t2;
        }
        return head;
    }
};
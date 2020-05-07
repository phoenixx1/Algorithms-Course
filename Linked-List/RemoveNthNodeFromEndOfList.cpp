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

//Given a linked list, remove the n-th node from the end of list and return its head.

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head;
        
        for(int i = 0; i < n; i++){
            if(second->next == NULL){
                if(i == n - 1){
                    head = head->next;
                }
                return head;
            }
            second = second->next;
        }
        
        while(second->next != NULL){
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};
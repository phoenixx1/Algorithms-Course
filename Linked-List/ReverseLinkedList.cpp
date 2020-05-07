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
Reverse a singly linked list.

https://leetcode.com/problems/reverse-linked-list/
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head; 
        ListNode *prev = NULL, *next = NULL; 
        while (current != NULL) { 
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        } 
        head = prev; 
        return head;
    }
};
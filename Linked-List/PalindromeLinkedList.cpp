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
Given a singly linked list, determine if it is a palindrome.

https://leetcode.com/problems/palindrome-linked-list/
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        stack<int> s;
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        while(head != NULL){
            int value = s.top();
            s.pop();
            if(head->val != value){
                return false;
            }
            head = head->next;
        }
        return true;
    }
};
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> stack;

        // zero or one Linked List member
        if(head == NULL || head->next == NULL) return true;

        ListNode* parser = head;
        int size = 0;
        while(parser != NULL){
            size++;
            parser = parser->next;
        }

        for (int i=0; i<size; i++){
            if(i == size/2 && size % 2 == 1){
                //nop
            }
            else if(i > size/2 - 1){
                if(stack.back() == head->val){
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
            else {
                stack.push_back(head->val);
            }
            
            head = head->next;
        }
        return true;
    }
};
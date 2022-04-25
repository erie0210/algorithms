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
    ListNode* dfs(ListNode* l1, ListNode* l2, int carry){   
        if(l1 == NULL and l2 == NULL){
            if(carry){
                return new ListNode(1);                
            }
            return NULL;
        };
        
        int sum = carry;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        ListNode* node = new ListNode(sum % 10);

        
        if(sum>9)   node->next = dfs(l1, l2, 1);
        else node->next = dfs(l1, l2, 0);
        
        return node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = dfs(l1, l2, 0);
        return result;
    }
};
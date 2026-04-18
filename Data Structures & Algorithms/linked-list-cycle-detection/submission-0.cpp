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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*>st;
  
    while (head != nullptr) {

        // if this node is already present
        // in hashmap it means there is a cycle
        if (st.find(head) != st.end())
            return true;

        // if we are seeing the node for
        // the first time, insert it in hash
        st.insert(head);

        head = head->next;
    }
    return false;
    }
};

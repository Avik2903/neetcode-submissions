/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur=root;
        while(cur!=nullptr)
        {
            if(cur->left==nullptr)
            {
                k--;
                if (k == 0) return cur->val;
                cur=cur->right;
            }
            else
            {
                TreeNode* prev=cur->left;
                while(prev->right!=nullptr && prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(prev->right==nullptr)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    prev->right=nullptr;
                    k--;
                    if (k == 0) return cur->val;
                    cur=cur->right;
                }
            }
        }
        
        return -1;
    }
};

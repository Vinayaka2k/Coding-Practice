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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int sum = 0;
        if(!root)
            return 0;
        if(root->val >= high){
            if(root->val == high)
                sum+=root->val;
            return sum+rangeSumBST(root->left, low, high);
        }
        
        else if(root->val <= low){
            if(root->val == low)
                sum += root->val;
            return sum+rangeSumBST(root->right, low, high);
        }
        
        else{
            return rangeSumBST(root->left, low, high) + root->val + rangeSumBST(root->right, low, high);
        }
    }
};
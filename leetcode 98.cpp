class Solution {
public:

    bool check(TreeNode* root, long long mini, long long maxi) {

        if (root == NULL)
            return true;

        if (root->val <= mini || root->val >= maxi)
            return false;

        bool left = check(root->left, mini, root->val);

        bool right = check(root->right, root->val, maxi);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};




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
    void validBST(TreeNode* root, TreeNode* &prev, bool &ans){
        if(root == NULL){
            return;
        }
        validBST(root->left,prev,ans);
        if(prev!= NULL && prev->val>= root->val){
            ans=false;
            return;
        }
        prev = root;
         validBST(root->right,prev,ans);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool ans = true;
        validBST(root,prev,ans);
        return ans;
    }
};
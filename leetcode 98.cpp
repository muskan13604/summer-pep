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
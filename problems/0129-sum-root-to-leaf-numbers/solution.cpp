class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        current = current * 10 + node->val;

        if (!node->left && !node->right) return current;
        
        return dfs(node->left, current) + dfs(node->right, current);
    }
};

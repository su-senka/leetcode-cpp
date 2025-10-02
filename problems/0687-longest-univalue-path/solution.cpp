class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxDistance = 0;
        dfs(root, maxDistance);

        return maxDistance;
    }

private:
    int dfs(TreeNode* node, int& maxDistance){
        if (!node) return 0;

        int L = dfs(node->left,  maxDistance);
        int R = dfs(node->right, maxDistance);

        int leftArm = (node->left && node->left->val == node->val) ? L + 1 : 0;
        int rightArm = (node->right && node->right->val == node->val) ? R + 1 : 0;

        maxDistance = max(maxDistance, leftArm + rightArm);

        return max(leftArm, rightArm);
    }
};

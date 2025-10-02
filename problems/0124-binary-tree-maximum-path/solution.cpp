class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        dfs(root, globalMax);

        return globalMax;
    }

private:
    int dfs(TreeNode* node, int& globalMax){
        if (!node) return 0;

        int leftGain = dfs(node->left, globalMax);
        int rightGain = dfs(node->right, globalMax);

        leftGain  = std::max(leftGain, 0);
        rigthGain = std::max(rigthGain, 0);

        globalMax = max(globalMax, node->val + leftGain + rigthGain);

        return node->val + max(leftGain, rightGain);
    }
};

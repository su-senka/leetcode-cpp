class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        vector<int> res;

        while (curr){
            st.push(curr);
            curr = curr->left;

            while (curr != nullptr || !st.empty()) {
                while (curr != nullptr) {
                    st.push(curr);
                    curr = curr->left;
                }

                curr = st.top();
                st.pop();
                res.push_back(curr->val);

                curr = curr->right;
            }
        }

        return res;
    }
};

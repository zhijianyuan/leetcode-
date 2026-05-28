class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> cur;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                TreeNode* p = q.front(); q.pop();
                level.push_back(p->val);
                if (p->left)  q.push(p->left);
                if (p->right) q.push(p->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

};
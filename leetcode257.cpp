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
    void path_find(TreeNode* root,string path, vector<string>& paths){
        if(root == nullptr){
            return ;
        }
        path += to_string(root->val);
        if(root->left == nullptr &&root->right == nullptr){
            paths.push_back(path);
        }
        else{
            path +="->";
            path_find(root->left,path,paths);
            path_find(root->right,path,paths);
        }        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        path_find(root, "", paths);
        return paths;
    }
};
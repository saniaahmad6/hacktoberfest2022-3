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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode *> q;
        stack <TreeNode *> st;
        vector<vector<int>> v;
        bool reverse=false;
        if (!root) return v;
        q.push(root);
        while (!q.empty()){
            int size=q.size();
            vector <int> curr;
            for (int i=0;i<size;i++){
                TreeNode *e= q.front();
                
                if (e->left) q.push(e->left);
                if (e->right) q.push(e->right);
                if (reverse){
                    st.push(q.front());
                }
                else{
                   curr.push_back(e->val);
                }
                q.pop();
            }
            if (reverse){
                while (!st.empty()) {
                    curr.push_back(st.top()->val);
                    st.pop();
                }
            }
            reverse=!reverse;
            v.push_back(curr);
        }
        return v;
    }
};

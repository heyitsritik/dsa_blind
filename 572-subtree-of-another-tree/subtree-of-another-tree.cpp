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
    bool same(TreeNode* p, TreeNode* q){
        if(!p and !q) return true;
        if(!p or !q or p->val != q->val) return false;

        return same(p->left,q->left) and same(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot){
            return true;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(subRoot->val == node->val){
                // cout<<"same"<<endl;
                if(same(subRoot,node)){
                    return true;
                    break;
                }
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};
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
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode* > q;
        q.push(root);
        bool leftToRight= true;
        while(!q.empty()){
            int s= q.size();
            vector<int> zigZagLevel(s);
            for(int i=0;i<s;i++){
                TreeNode* node= q.front();
                q.pop();
                int index;
                if(leftToRight){
                    index=i;
                }else{
                    index= s-i-1;
                }
                zigZagLevel[index]=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            leftToRight=!leftToRight;
            result.push_back(zigZagLevel);
        }
        return result;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        vector<Node*> v;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            v.push_back(temp);
            if(temp==NULL){
                if(q.empty()){
                    break;
                }
                v.push_back(NULL);
                q.push(NULL);
                continue;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==NULL){
                continue;
            }
            v[i]->next=v[i+1];
        }
        return root;
    }
};
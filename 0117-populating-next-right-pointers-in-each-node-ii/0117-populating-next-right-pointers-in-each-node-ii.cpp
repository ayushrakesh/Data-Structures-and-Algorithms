

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            Node* prev=NULL;
            for(int i=0;i<size;i++){
                Node* curr=qu.front();
                qu.pop();
                if(prev){
                    prev->next=curr;
                }
                prev=curr;
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
                


            }
        }
        return root;
    }
};
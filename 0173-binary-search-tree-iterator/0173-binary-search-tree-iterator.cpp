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
 class Node{
     public: 
       int value;
       Node*next ;

       Node(int val ){
           this->value = val;
           this->next = nullptr;
       }
 };

class BSTIterator {
public:
    Node*head = nullptr ;
    Node*tail = nullptr ;
    void insertAtTail(int val){
        Node * newnode = new Node(val);

        if(head == nullptr){
            head = newnode ;
            tail = newnode ;
        }else{
            tail->next = newnode ;
            tail = newnode ;
        }
    }
    void inorder(TreeNode * root){
        if(root == nullptr){
            return ;
        }
        inorder(root->left);
        insertAtTail(root->val);
        inorder(root->right);
        
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int val =0 ;
        if(head != nullptr){
            val = head -> value ;
            head = head ->next ;
        }  
        return val ;
    }
    
    bool hasNext() {
         return head != nullptr ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
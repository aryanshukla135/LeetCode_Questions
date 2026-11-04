/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node * node , Node * clone_node , unordered_map<Node*,Node*>& mp){
        for(Node * n : node->neighbors){
            if(!mp.count(n)){
                Node * clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n,clone,mp);
            }else{
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp ;
        if(!node){
            return nullptr;
        }

        Node * clone_node = new Node(node->val);
        mp[node] = clone_node;

        dfs(node,clone_node,mp);

        return clone_node;
    }
};
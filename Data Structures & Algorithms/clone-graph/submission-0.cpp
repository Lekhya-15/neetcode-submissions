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
public:
    Node* dfs(unordered_map<Node*,Node*>& map,Node* n){
        if(!n) return n;
        if(map.count(n)) return map[n];
        Node* node=new Node(n->val);

        map[n]=node;
        for(Node* ne:n->neighbors){
            node->neighbors.push_back(dfs(map,ne));
        }
        
        return node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> map;
        Node* root=dfs(map,node);
        return root;
    }
};

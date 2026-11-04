/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> mp;
        mp[NULL]=NULL;

        Node* root = new Node(head->val);
        mp[head] = root;
        Node* curr = head;

        while(head->next){
            head = head->next;
            root->next = new Node(head->val);
            root = root->next;
            mp[head] = root;
        }

        for(auto [x,y]:mp){
            if(!x) continue;
            y->random = mp[x->random];
        }

        return mp[curr];
    }
};

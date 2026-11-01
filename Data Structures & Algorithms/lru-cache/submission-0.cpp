class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k,int v):key(k),value(v),prev(NULL),next(NULL){}
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*> map;
    Node* left;
    Node* right;
    
public:
    LRUCache(int capacity) {
        map.clear();
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(!map.count(key)) return -1;

        map[key]->prev->next=map[key]->next;
        map[key]->next->prev=map[key]->prev;

        right->prev->next=map[key];
        map[key]->prev=right->prev;
        map[key]->next=right;
        right->prev=map[key];

        return map[key]->value;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
        map[key]->prev->next=map[key]->next;
        map[key]->next->prev=map[key]->prev;

        right->prev->next=map[key];
        map[key]->prev=right->prev;
        map[key]->next=right;
        right->prev=map[key];

        map[key]->value=value;
        }
        else{
            if(map.size()==capacity){
                Node* node=left->next;
                node->prev->next=node->next;
                node->next->prev=node->prev;
                map.erase(node->key);
            }
            Node* root=new Node(key,value);
            
            right->prev->next=root;
            root->prev=right->prev;
            root->next=right;
            right->prev=root;

            map[key]=root;
        }
    }
};

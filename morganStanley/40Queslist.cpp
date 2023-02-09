// LRU CACHE
class LRUCache {
public:
    class node{
        public: 
        int keynode;
        int valnode;
        node* next;
        node* prev;
        node(int _key, int _val)
        {
            keynode = _key;
            valnode= _val;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    
    unordered_map<int,node*>mp;

    LRUCache(int capacity) {
        cap =capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node * newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node * delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            node * resnode = mp[key];
            int res = resnode->valnode;
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node * existing = mp[key];
            mp.erase(key);
            deletenode(existing);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->keynode);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

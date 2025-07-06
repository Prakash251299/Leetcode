struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int d,int e) {
       key = d;
       val = e;
       prev = next = NULL;      
    }
};
class LRUCache {
public:
    void display(Node *dl){
        while(dl!=NULL){
            cout<<dl->key<<":"<<dl->val<<"\n";
            dl=dl->next;
        }
        cout<<"\n";
    }
    int lruSz=0,sz=0;
    // Node* dl = NULL;
    map<int,Node*>m;
    Node *start=NULL;
    Node *end=NULL;
    LRUCache(int capacity) {
        lruSz = capacity;
    }
    
    int get(int key) {
        if(start==NULL){
            return -1;
        }
        if(m[key]==NULL){
            return -1;
        }
        if(sz==1){
            return m[key]->val;
        }
        if(key==end->key){
            return end->val;
        }
        if(key==start->key){
            Node* currNode = m[key];
            start = start->next;
            start->prev = NULL;
            end->next = currNode;
            end->next->prev = end;
            end = end->next;
            m[key] = end;
            end->next = NULL;
            return m[key]->val;
        }
        m[key]->next->prev = m[key]->prev;
        m[key]->prev->next = m[key]->next;
        end->next = m[key];
        end->next->prev = end;
        end = end->next;
        m[key] = end;
        end->next = NULL;
        // }
        return m[key]->val;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key,value);
        if(m[key]==NULL){
            if(sz<lruSz){
                if(sz==0){
                    start = newNode;
                    end = start;
                }else{
                    end->next = newNode;
                    newNode->prev = end;
                    end = end->next;
                }
                sz++;
            }else{
                if(sz==lruSz){
                    if(sz==1){
                        m[start->key] = NULL;
                        start = newNode;
                        end = start;
                    }else{
                        m[start->key]=NULL;
                        start = start->next;
                        start->prev = NULL;
                        end->next = newNode;
                        newNode->prev = end;
                        end = end->next;
                    }
                }
            }
        }else{
            if(key==end->key){
                end->val = value;
                return;
            }else{
                if(start->key == key){
                    start=start->next;
                    start->prev = NULL;
                    end->next = newNode;
                    newNode->prev = end;
                    end = end->next;
                }else{
                    m[key]->prev->next = m[key]->next;
                    m[key]->next->prev = m[key]->prev;
                    end->next = newNode;
                    newNode->prev = end;
                    end = end->next;
                }
            }
        }
        m[key] = newNode;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

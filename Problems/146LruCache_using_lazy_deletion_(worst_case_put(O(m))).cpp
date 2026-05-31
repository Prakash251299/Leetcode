class LRUCache {
public:
    unordered_map<int,int>counter;
    unordered_map<int,int>m;
    queue<int>lru;
    int csz=0;
    int sz=0;

    void display(queue<int>q){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        return;
    }
    void display(unordered_map<int,int>&m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
        return;
    }

    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        if(counter[key]>0){
            counter[key]++;
            lru.push(key);
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(counter[key] > 0){
            lru.push(key);
            counter[key]++;
            m[key]=value;
            return;
        }
        if(csz<sz){
            lru.push(key);
            counter[key]++;
            m[key]=value;
        }else{
            while(counter[lru.front()]>1){
                counter[lru.front()]--;
                lru.pop();
            }
            counter[lru.front()]--;
            lru.pop();
            counter[key]++;
            lru.push(key);
            m[key]=value;
        }
        csz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

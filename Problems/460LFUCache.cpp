class LFUCache {
public:
    int lfuSz = 0;
    int sz = 0;
    unordered_map<int,list<int>::iterator>add;
    unordered_map<int,int>m; // for count
    unordered_map<int,int>valueMap; // for value
    unordered_map<int,list<int>>taskWithCount;
    int minFreq=1;
    LFUCache(int capacity) {
        lfuSz = capacity;
    }
    
    int get(int key) {
        if(m[key]==0){
            return -1;
        }
        if(m[key]==minFreq && taskWithCount[minFreq].size()==1){
            ++m[key];
            taskWithCount[minFreq].pop_front();
            minFreq++;
            taskWithCount[m[key]].push_back(key);
            auto last = taskWithCount[m[key]].end();
            last--;
            add[key] = last;
            return valueMap[key];
        }else{
            taskWithCount[m[key]].erase(add[key]);
            ++m[key];
            taskWithCount[m[key]].push_back(key);
            auto last = taskWithCount[m[key]].end();
            last--;
            add[key] = last;
            return valueMap[key];
        }
        return valueMap[key];
    }
    
    void put(int key, int value) {
        valueMap[key] = value;
        if(m[key]==0){
            if(lfuSz==sz){
                // lsSz = taskWithCount[minFreq].size();
                auto fr = taskWithCount[minFreq].begin();
                m[*fr] = 0;
                // add[*fr];
                taskWithCount[minFreq].pop_front();
                minFreq = 1;
                m[key] = 1;
                taskWithCount[1].push_back(key);
                auto last = taskWithCount[minFreq].end();
                last--;
                add[key] = last;
                return;
            }
            if(sz<lfuSz){
                m[key] = 1;
                minFreq = 1;
                taskWithCount[m[key]].push_back(key);
                auto last = taskWithCount[m[key]].end();
                last--;
                add[key] = last;
                sz++;
                return;
            }
        }else{
            if(m[key]==minFreq && taskWithCount[minFreq].size()==1){
                ++m[key];
                taskWithCount[minFreq].pop_front();
                minFreq++;
                taskWithCount[m[key]].push_back(key);
                auto last = taskWithCount[m[key]].end();
                last--;
                add[key] = last;
                return;
            }else{
                taskWithCount[m[key]].erase(add[key]);
                ++m[key];
                taskWithCount[m[key]].push_back(key);
                auto last = taskWithCount[m[key]].end();
                last--;
                add[key] = last;
                return;
            }
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

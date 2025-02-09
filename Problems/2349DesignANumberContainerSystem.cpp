class NumberContainers {
public:
    unordered_map<int,int>m; // for index wise numbers
    /* Each number's indexes is store in the map too so that it can be checked in O(N) time */
    unordered_map<int,map<int,int>>min; // for numbers wise indexes
    NumberContainers(){}
    
    void change(int index, int number) {
        min[number][index] = 1;
        if(m[index]!=0){
            if(m[index]!=number){
                min[m[index]].erase(index);
            }
        }
        m[index] = number;
    }
    
    int find(int number) {
        if(min[number].size()==0){
            return -1;
        }
        auto it = *min[number].begin();
        return it.first;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

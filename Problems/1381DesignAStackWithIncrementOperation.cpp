class CustomStack {
public:
    vector<int>v;
    int size=0;
    int count=0;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(count<size){
            v.push_back(x);
            count++;
        }
        // display(v);
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    
    int pop() {
        if(v.size()>0){
            // cout<<v[v.size()-1]<<" ";
            int t = v[v.size()-1];
            v.pop_back();
            // cout<<v.size()<<" ";
            count--;
            // if(v.size()>0){
            //     display(v);
            // }
            return t;
                // return v[v.size()-1];
            // }
        }
        // display(v);
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<v.size();i++){
            v[i]+=val;
        }
        // display(v);
        // for(int i=0;i<v.size() && i<k;i++){
        //     v[v.size()-i-1]+=val;
        // }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

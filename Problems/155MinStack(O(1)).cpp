class MinStack {
public:
    vector<int>v;
    vector<int>minS;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        if(minS.empty()){
            minS.push_back(val);
        }else{
            int top=minS[minS.size()-1];
            if(top<val){
                minS.push_back(top);
            }else{
                minS.push_back(val);
            }
        }
    }
    
    void pop() {
        if(!v.empty()){
            v.pop_back();
            minS.pop_back();
        }
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return minS[minS.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

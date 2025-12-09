class StockSpanner {
public:
    vector<int>rem;
    vector<int>v;
    StockSpanner() {
        
    }
    
    int next(int price){
        int c=1;
        while(v.size()!=0&&v[v.size()-1]<=price){
            c+=rem[rem.size()-1];
            rem.pop_back();
            v.pop_back();
        }
        v.push_back(price);
        rem.push_back(c);
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>l;
        vector<int>h;
        // For getting minimum element before current
        l.push_back(prices[0]);
        for(int i=1;i<prices.size();i++){
            if(prices[i]<l[i-1]){
                l.push_back(prices[i]);
            }else{
                l.push_back(l[i-1]);
            }
        }
        h=l;
        // For getting maximum element after current
        h[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]>h[i+1]){
                h[i]=prices[i];
            }else{
                h[i]=h[i+1];
            }
        }
        int diff=0;
        for(int i=0;i<prices.size();i++){
            if(h[i]-l[i]>diff){
                diff=h[i]-l[i];
            }
        }
        return diff;
    }
};

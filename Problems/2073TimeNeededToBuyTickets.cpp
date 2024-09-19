class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets[k]==1){
            return k+1;
        }
        int c=0;
        for(int i=0;tickets[k]>0;i++){
            if(tickets[i]>0){
                c++;
            }
            if(tickets[i]>0)
            tickets[i]-=1;
            if(i+1==tickets.size()){
                i=-1;
            }
        }
        return c;
    }
};

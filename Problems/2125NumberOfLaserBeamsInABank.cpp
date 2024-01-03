class Solution {
public:
    int countOne(string s){
        int a=0;
        for(int i=0;i<s.size();i++){
                a += s[i] - '0';
        }
        return a;
    }

    int numberOfBeams(vector<string>& bank) {
        int count=0,prev=0,curr=0;
        for(int i=0;i<bank.size();i++){
            curr = countOne(bank[i]);
            if(prev>0){
                if(curr>0){
                    count+=prev*curr;
                    prev = curr;
                }
            }else{
                if(curr>0){
                    prev = curr;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>v=digits;
        // int i=v.size()-1;
        int rem=1;
        for(int i=v.size()-1;i>=0;i--){
            v[i]+=rem;
            if(v[i]>9){
                v[i]=0;
            }else{
                return v;
            }
        }
        // If 1st digit is changed then at front 1 will be pushed
        // back that's why a new vector which is initially pushed by 1
        // gets all the digits of original vector, after that, and returned
        digits.clear();
        if(v[0]==0){
            digits.push_back(1);
            for(int j=0;j<v.size();j++){
                digits.push_back(v[j]);
            }
        }
        return digits; 
    }
};

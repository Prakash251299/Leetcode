class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        vector<int>stack;
        long long c=0;
        for(auto curr:nums){
            if(stack.empty()){
                stack.push_back(curr);
                continue;
            }
            if(stack.size()==1){
                if(stack[stack.size()-1]<curr){
                    stack.clear();
                    //stack.push_back(curr);
                    //continue;
                }
                stack.push_back(curr);
                continue;
            }
            while(1){
                if(stack.size()==0){
                    break;
                }
                if(stack[stack.size()-1]<curr){
                    if(stack.size()>=2){
                        stack.pop_back();
                        c++;
                    }else{
                        stack.clear();
                    }
                    
                }else{break;}
            }
            stack.push_back(curr);
        }
        return c;
    }
};

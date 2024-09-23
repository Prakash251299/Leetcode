class Solution {
public:
    void traverse(int sum,int n,vector<int>&r){
        // cout<<sum<<" ";
        int t = sum;
        for(int i=1;;i++){
            if(sum%10==0 && sum!=t){
                return;
            }
            if(sum>n){
                return;
            }
            r.push_back(sum);
            if(sum*10<=n){
                traverse(sum*10,n,r);
            }
            sum++;
        }
        return;
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res;
        traverse(1,n,res);
        return res;
    }
};

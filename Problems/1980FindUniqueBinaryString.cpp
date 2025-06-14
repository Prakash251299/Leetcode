class Solution {
public:
    void findBinaryStr(map<string,int>&m,int n,string &res,string temp){
        if(res!=""){
            return;
        }
        if(temp.size()==n){
            if(m[temp]==0){
                res=temp;
            }
            return;
        }
        findBinaryStr(m,n,res,temp+'0');
        findBinaryStr(m,n,res,temp+'1');
        return;

    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string,int>m;
        for(auto x:nums){
            ++m[x];
        }
        string res="",temp="0";
        findBinaryStr(m,n,res,temp);
        if(res!=""){
            return res;
        }
        temp="1";
        findBinaryStr(m,n,res,temp);
        return res;
    }
};

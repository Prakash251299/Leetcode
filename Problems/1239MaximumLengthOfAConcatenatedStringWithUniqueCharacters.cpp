class Solution {
public:
    int max=0;
    int unique1(string a){
        unordered_map<char,int>m;
        for(auto x:a){
            ++m[x];
            if(m[x]>1){
                return 0;
            }
        }
        return 1;
    }

    void add(string a,int i,vector<string>v){
        if(unique1(a)){
            for(int j=i;j<v.size();j++){
                add(a+v[j],j+1,v);
            }
            if(max<a.size()){
                max = a.size();
            }
        }
        return;
    }

    int maxLength(vector<string>& arr) {
        string s="";
        for(int i=0;i<arr.size();i++){
            add(s+arr[i],i+1,arr);
            s = "";
        }
        return max;
    }
};

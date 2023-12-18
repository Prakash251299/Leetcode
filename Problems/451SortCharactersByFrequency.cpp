class Solution {
public:
    string frequencySort(string s) {
        vector<int>v;
        vector<char>v1;
        unordered_map<int,vector<char>>m;
        string str = "";
        for(int i=0;i<256;i++){
            v.push_back(0);
        }
        for(int i=0;i<s.size();i++){
            ++v[s[i]];
        }
        for(int i=0;i<256;i++){
            if(v[i]>0){
                m[v[i]].push_back(char(i));
                // cout<<char(i)<<":"<<v[i]<<"\n";
                // for(int j=0;j<v[i];j++){
                //     str = str + char(i);
                // }
            }
        }
        // for(auto x:m){
        //     cout<<x.first<<":";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        sort(v.begin(),v.end(),greater<int>());
        int temp=0;
        s = "";
        for(int i=0;i<v.size();i++){
            if(i>0 and v[i]==temp){
                continue;
            }
            temp = v[i];
            if(v[i]>0){
                for(auto x:m[v[i]]){
                    for(int j=0;j<v[i];j++){
                        v1.push_back(x);
                        // s = s + x;
                    }
                }
                // for(int j=0;j<m[v[i]].size();j++){
                //     str = str + 
                // }
            }
            // cout<<v[i]<<" ";
        }


        ///////// For converting vector of chars to string ////////
        // meth-1:
        // string stri(v1.begin(), v1.end());
        // return stri;

        // meth-2
        // stringstream ss;
        // for(auto x:v1){
        //     ss<<x;
        // }
        // return ss.str();

        // meth-3
        // for(auto x:v1){
        //     s.push_back(x);
        // }
        // return s;

        // meth-4
        for(auto x:v1){
            s.append(1,x);
        }
        return s;
    }
};

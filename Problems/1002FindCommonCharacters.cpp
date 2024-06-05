class Solution {
public:
    vector<string> find(unordered_map<char,int>m,vector<string> v){
        vector<string> res;
        for(int i=1;i<v.size();i++){
            unordered_map<char,int>m1;
            for(int j=0;j<v[i].size();j++){
                ++m1[v[i][j]];
            }
            for(auto y:m){
                /* If the count is less than in the next string then only updation is done because there may be cases when other strings contain more number of that charatcer which will update the count (larger counts are need not to be updated as we need minimum number of string count) */
                if(m[y.first]>=m1[y.first]){
                    m[y.first]=m1[y.first];
                }
            }
        }

        for(auto x:m){
            if(x.second>0){
                for(int i=0;i<x.second;i++){
                    string s;
                    s.append(1, x.first);
                    res.push_back(s);
                }
            }
            // cout<<x.first<<":"<<x.second;
        }
        return res;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        unordered_map<char,int>m;
        /* First of all we are extracting each character of first string and matching it to other strings of the array */
        /* For that we are finding the count of each cahracter in first string and if the count for each single character is found in other strings then the count for first string is updated which tells than how many matches has been found in other strings */
        for(int j=0;j<words[0].size();j++){
            ++m[words[0][j]];
        }
        res =find(m,words);
        return res;
    }
};

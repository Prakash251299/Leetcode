class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=0;j<matrix[0].size();j++){
                if(i==matrix.size()-1){
                    v[i][j]=int(matrix[i][j])-int('0');
                    continue;
                }
                if(int(matrix[i][j])-int('0')==0){
                    v[i][j]=0;
                    continue;
                }
                v[i][j]=int(matrix[i][j])+int(v[i+1][j])-int('0');
            }
        }
        vector<vector<int>>lr(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>rl(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            vector<int>st;
            for(int j=0;j<matrix[0].size();j++){
                if(j==0){
                    lr[i][j]=-1;
                    st.push_back(-1);
                    st.push_back(j);
                    continue;
                }
                while(st[st.size()-1]!=-1 && v[i][st[st.size()-1]]>=v[i][j]){
                    st.pop_back();
                }
                if(st[st.size()-1]==-1){
                    lr[i][j]=-1;
                    st.push_back(j);
                    continue;
                }
                lr[i][j]=st[st.size()-1];
                st.push_back(j);
            }
            st.clear();
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(j==matrix[0].size()-1){
                    rl[i][j]=matrix[0].size();
                    st.push_back(matrix[0].size());
                    st.push_back(j);
                    continue;
                }
                while(st[st.size()-1]!=matrix[0].size() && v[i][st[st.size()-1]]>=v[i][j]){
                    st.pop_back();
                }
                if(st[st.size()-1]==matrix[0].size()){
                    rl[i][j]=matrix[0].size();
                    st.push_back(j);
                    continue;
                }
                rl[i][j]=st[st.size()-1];
                st.push_back(j);
            }
        }
        int maxr=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val = v[i][j]*(rl[i][j]-lr[i][j]-1);
                if(val>maxr){
                    maxr=val;
                }
            }
        }
        return maxr;
    }
};

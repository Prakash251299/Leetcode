/* Time complexity: O(m x n x 4^k), k = length of word, 4 because every letter of word has 4 directions */

class Solution {
public:
    int found = 0;

    int isValid(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        return 1;
    }

    void fun(int i, int j, vector<vector<char>>& v, string word, int k,int m, int n){
        if(k>=word.size()){
            found=1;
            return;
        }
        if(isValid(i,j,m,n)){
            if(word[k]==v[i][j]){
                v[i][j] = '.';
                if(found==0)
                fun(i+1,j,v,word,k+1,m,n);
                if(found==0)
                fun(i-1,j,v,word,k+1,m,n);
                if(found==0)
                fun(i,j+1,v,word,k+1,m,n);
                if(found==0)
                fun(i,j-1,v,word,k+1,m,n);
                v[i][j] = word[k];
            }
        }

        /* It also works but time limit exceeding */
        // if(found==0){
        //     if(isValid(i,j+1,v,m,n)){
        //         if(v[i][j+1]==word[k]){
        //                 v[i][j+1] = '.';
        //                 fun(i,j+1,v,word,k+1,m,n);
        //                 v[i][j+1] = word[k];
        //             // }
        //         }
        //     }
        // }
        // if(found==0){
        //     if(isValid(i+1,j,v,m,n)){
        //         if(v[i+1][j]==word[k]){
        //                 v[i+1][j] = '.';
        //                 fun(i+1,j,v,word,k+1,m,n);
        //                 v[i+1][j] = word[k];
        //             // }
        //         }
        //     }
        // }
        // if(found==0){
        //     if(isValid(i-1,j,v,m,n)){
        //         if(v[i-1][j]==word[k]){
        //                 v[i-1][j] = '.';
        //                 fun(i-1,j,v,word,k+1,m,n);
        //                 v[i-1][j] = word[k];
        //             // }
        //         }
        //     }
        // }
        // if(found==0){
        //     if(isValid(i,j-1,v,m,n)){
        //         if(v[i][j-1]==word[k]){
        //                 v[i][j-1] = '.';
        //                 // searched[i][j-1] = 1;
        //                 fun(i,j-1,v,word,k+1,m,n);
        //                 v[i][j-1] = word[k];
        //             // }
        //         }
        //     }
        // }
        return;
    }


    /* This is copied from somewhere but not in use */
    // bool fun1(int i, int j, vector<vector<char>>& v,string word, int k, int m, int n){
    //     bool a,b,c,d;
    //     if(k>=word.size()){
    //         found=1;
    //         return true;
    //     }
    //     if(i<0||j<0||i>=m||j>=n||v[i][j]!=word[k]){
    //         return false;
    //     }
    //     v[i][j] = '.';
    //     a = fun1(i,j+1,v,word,k+1,m,n);
    //     b = fun1(i+1,j,v,word,k+1,m,n);
    //     c = fun1(i-1,j,v,word,k+1,m,n);
    //     d = fun1(i,j-1,v,word,k+1,m,n);
    //     v[i][j] = word[k];

    //     return a||b||c||d;
    // }

    bool exist(vector<vector<char>>& v, string word) {
        int i=0,j=0,k=0,a=0;
        int m = v.size();
        int n = v[0].size();
        // return false;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==word[0]){
                    fun(i,j,v,word,0,m,n);
                    if(found==1){
                        return true;
                    }

                    /* This should be uncommented if want to use the 2nd function */
                    // if(fun1(i,j,v,word,0,m,n)){
                    //     return true;
                    // }
                }
            }
        }
        return false;
    }
};
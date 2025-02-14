class Solution {
public:
    void display(stack<int>v){
       while(!v.empty()){
        cout<<v.top()<<" ";
        v.pop();
       }
        cout<<"\n";
    }

    int check(string s,int i, int j){
        // cout<<"i:"<<i<<" j:"<<j<<"\n";
        if(s[i]=='(' && s[j]==')'){
            return 1;
        }
        return 0;
    }

    int longestValidParentheses(string s) {
        if(s.size()==0 || s.size()==1){
            return 0;
        }
        int max = 0, i = 0;
        stack<int>v;
        v.push(-1);
        while(1){
            // if(v.size()==0){
            //     break;
            // }
            if(i==s.size()){
                break;
            }
            if(s[i]==')'){
                v.pop();
                if(v.size()==0){
                    v.push(i);
                }else{
                    if(max<i-v.top()){
                        max = i-v.top();
                    }
                }
            }else{
                v.push(i);
            }
            i++;
        }
        return max;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string num="1";
        if(n==1){
            return num;
        }
        for(int i=1;i<n;i++){
            num = count(num);
        }
        return num;
    }
    string count(string num){
        string res="";
        int count=0;
        for(int i=0;i<num.size();i++){
            count=counter(num[i],num,i);
            res=res+to_string(count)+num[i];
            i+=count-1;
        }
        return res;
    }
    int counter(char a,string num,int i){
        int count=0;
        for(;i<num.size();i++){
            if(num[i]!=a){
                return count;
            }
            count++;
        }
        return count;
    }
};

class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void check(string &s,int &i,int &j,int &n,int &tempMid){
        while(i>=0&&j<n){
            if(s[i]!=s[j])break;
            i--;j++;
        }
        return;
    }
    string longestPalindrome(string s1) {
        int maxSz=0,left=0,right=0,i=0,j=0,mid=0,l=0,r=0;
        string s="$";
        for(auto x:s1){
            s=s+x+'$';
        }       
        int n=s.size();
        int finalMid=0;
        vector<int>mirr(n+1,0);
        for(int tempMid=0;tempMid<n;tempMid++){
            //int ind=mid-(tempMid-mid);                      
            if(tempMid<r){
                    i=tempMid-min(mirr[2*mid-tempMid],r-tempMid);
                    j=tempMid+ min(mirr[2*mid-tempMid],r-tempMid);
            }else{
                mid =tempMid;
                i=tempMid;
                j=tempMid;
            }
            check(s,i,j,n,tempMid);
            i++;j--;            
            mirr[tempMid]=tempMid-i;
            if(j-i+1>maxSz){
                left=i;right=j;
                maxSz=j-i+1;
                finalMid=tempMid;
            }
            if(j>r){
                mid=tempMid;
                l=i;r=j;                
            }            
        }        
        //s="";
        string res="";
        //cout<<left<<":"<<right<<"->"<<finalMid<<"\n";
        for(i=left;i<=right;i++){
            if(s[i]!='$')
            res+=s[i];
        }
        return res;
        //return "";
    }
};

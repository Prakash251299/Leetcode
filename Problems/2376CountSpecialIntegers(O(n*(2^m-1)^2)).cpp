class Solution {
public:
    int getSimpleCount(int usedCount, int n){
        //cout<<"usedCount:"<<usedCount<<" "<<"n:"<<n<<endl;
        //if(usedCount==n)return 0;
        int multiplier=1;
        if(usedCount==0){
            multiplier=9-usedCount;
        }else{
            multiplier=10-usedCount;
        }
        int res=1;
        for(int i=usedCount+1;i<=n;i++){
            res*=multiplier;
            if(usedCount==0&&i<=usedCount+1)
                continue;
            multiplier--;
        }
        return res;
    }

    void solve(string num,vector<int>&used,int i,int &total,int &n){
        
        int startDigit=int(num[0]-'0');
        /*if(num.size()==1){
            cout<<"total:"<<total<<" oneSz:"<<startDigit<<endl;
            if(startDigit==0)
                total++;
            else
            total+=startDigit+1-i+1;
            return;
        }*/
        int diff=0;
        //if(num.size()==n){
        for(int j=0;j<=startDigit;j++){
            if(used[j]==1){
                diff++;
            }
        }
        
        //int myDigit=startDigit;
        //}else{
        //used[startDigit]=1;
        // startDigit--;
        //}
        if(num.size()==1){
            //if(n==1){total+=startDigit-diff;}else
            //cout<<"total:"<<total<<" strt:"<<startDigit<<endl;
            total+=(startDigit-diff+1);
            //cout<<"numSz1:"<<total<<endl;
            return;
        }
        if(used[startDigit]==1){
            //cout<<"fn:"<<total<<endl;
            total+=(startDigit-diff+1)*getSimpleCount(i,n);
            return;
        }
        used[startDigit]=1;
        if(i==1){
            startDigit--;
        }
        //cout<<"bfr tot:"<<total<<endl;
        if(startDigit!=0){
            int temp= getSimpleCount(i,n);
            //cout<<"temp:"<<temp<<endl;
            total+=(startDigit-diff)*temp;
        }
        //cout<<"after tot:"<<total<<endl;
        //if(num.size()>1)
        solve(num.substr(1),used,i+1,total,n);
        return;
    }
    
    int countSpecialNumbers(int n) {
        int total=0;
        string num=to_string(n);
        vector<int>used(10,0);
        //num=num.substr(1);
        //cout<<num;
        //return 0;
        int sz=num.size();
        if(sz==1){
            return n;
        }
        solve(num,used,1,total,sz);
        //cout<<"lastTot:"<<total<<endl;
        for(int i=num.size()-1;i>0;i--){
            total+=getSimpleCount(0,i);
        }

        //cout<<getSimpleCount(0,num.size());
        return total;
    }
};

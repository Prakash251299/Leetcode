class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int digits(int n){
        int c=0;
        while(n!=0){
            n/=10;
            c++;
        }
        return c;
    }
    void additiveFactors(int i,int sum,int num,int n,vector<int>v,vector<vector<int>>&comb){
        if(sum==n){
            comb.push_back(v);
            return;
        }
        if(sum>n){
            return;
        }
        for(int j=i+1;j<=n;j++){
            v.push_back(j);
            additiveFactors(j,sum+j,num,n, v, comb);
            v.pop_back();
        }
        return;
    }

    void getDigits(int num,vector<int>&numDigits){
        while(num!=0){
            numDigits.push_back(num%10);
            num/=10;
        }
        reverse(numDigits.begin(),numDigits.end());
        return;
    }

    int vecToNum(vector<int>&num){
        int res=0,p=num.size()-1;
        for(auto x:num){
            res+=x*pow(10,p);
            p--;
        }
        return res;
    }

    int check(vector<int>&freq,vector<int>&b,int i,vector<int>&v){
        /*if(i==0){
            cout<<"freq: ";display(freq);
            cout<<"num2: ";display(b);
        }*/
        if(i>=b.size()){
            return 1;
        }
        for(int j=b[i];j<=9;j++){
            if(freq[j]>0){
                v.push_back(j);--freq[j];
                if(j>b[i]){
                    for(int k=0;k<=9;k++){
                        for(int l=0;l<freq[k];l++){
                            v.push_back(k);
                        }
                    }
                    return 1;
                }
                int found=check(freq,b,i+1,v);
                if(found==1){return 1;}
                else{++freq[j];v.pop_back();}
            }
        }
        return 0;
    }
    
    int getBiggerNum(vector<int>&num1,vector<int>&num2){
        vector<int>freq(10,0);
        int total=0;
        for(auto x:num1){
            freq[x]=x;
            total+=x;
        }
        num1.clear();
        for(int i=9;i>=0;i--){
            for(int j=0;j<freq[i];j++){
                num1.push_back(i);
            }
        }
        //display(num1);
        int a=vecToNum(num1);
        //a=0;
        //cout<<"num1:"<<a<<"\n";
        int b=vecToNum(num2);
        //b++;
        //cout<<"num2:"<<b<<"\n";
        if(a<b){return INT_MAX;}//not possible then return with infinity
        vector<int>resNum;
        check(freq,num2,0,resNum);
        //cout<<"resNum:";display(resNum);
        int res=0;
        res=vecToNum(resNum);
        return res;
    }
    
    int getJustGreater(vector<vector<int>>&combinations,int num){
        vector<int>numDigits;
        int minNum=INT_MAX;
        getDigits(num,numDigits);
        for(auto x: combinations){
            int tempNum=getBiggerNum(x,numDigits);
            //cout<<tempNum<<"<-tempNum\n";
            if(tempNum>=num && minNum>tempNum){
                minNum=tempNum;
            }
        }
        //cout<<minNum<<"<-minNum\n";
        return minNum;
    }
    int caller(int num,int n){
        vector<vector<int>>combinations;
        int sum=0;
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
            additiveFactors(i,sum+i,num,n, v, combinations);
            v.pop_back();
        }
        //display(combinations);

        int res=getJustGreater(combinations,num);
        return res;
    }
    
    int nextBeautifulNumber(int num) {
        // return 0;
        /*vector<int>numDigits;
        getDigits(num,numDigits);
        display(numDigits);
        return 0;*/
        
        /*vector<int>freq={0,1,2,0,0,0,0,0,0,0};
        vector<int>b={2,1,3};
        vector<int>ans;
        check(freq,b,0,ans);
        cout<<"ans:";display(ans);

        return 0;*/

        num++;
        int n=digits(num);
        int res=caller(num,n);
        if(res==INT_MAX){
            n++;
            num=pow(10,n-1);
            res=caller(num,n);
        }
        return res;
    }
};

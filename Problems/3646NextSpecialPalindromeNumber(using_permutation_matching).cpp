class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(vector<long long>&v){
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
    void display(set<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void findLen(long long n,int &sz){
        if(n==0){sz=1;return;}
        while(n>0){
            sz++;
            n/=10;
        }
        return;
    }
    void divide(vector<int>&v,int i,vector<vector<int>>&res,int &sum,int &n,int &oddCount){
        if(sum==n){
            res.push_back(v);return;
        }
        if(sum>n){
            return;
        }
        /*if(i%2!=0){
            i++;
        }else{
            i+=2;
        }*/
        for(;i<10;i++){
            if(i%2!=0 && oddCount==1)continue;
            if(i%2!=0)oddCount=1;
            sum+=i;
            v.push_back(i);
            divide(v,i+1,res,sum,n,oddCount);
            if(i%2!=0)oddCount=0;
            v.pop_back();
            sum-=i;
        }
        return;
    }
    void storePerm(vector<int>&v,set<vector<int>>&sim,vector<int>&temp,vector<int>&visited){
        for(int i=0;i<v.size();i++){
            if(visited[i]==1){continue;}
            visited[i]=1;
            temp.push_back(v[i]);
            if(temp.size()==v.size()){
                sim.insert(temp);
            }
            storePerm(v,sim,temp,visited);
            temp.pop_back();
            visited[i]=0;
        }
        return;
    }
    void getPerm(vector<int>&v,set<vector<int>>&sim){
        vector<int>visited(v.size()+1,0);
        vector<int>temp;
        storePerm(v,sim,temp,visited);
        return;
    }
    
    void callArranger(set<vector<int>>&sim,vector<int>&perm,int sz){
        /*cout<<"perm\n";
        display(perm);*/
        int oddCount=0,a=0;
        /*if(perm[0]%2!=0){
            a=perm[0];
        }*/
        vector<int>v;
        for(auto x:perm){
            int val=x;
            if(x%2!=0){
                oddCount=1;a=x;
            }
            x/=2;
            while(x>0){
                v.push_back(val);
                x--;
            }
        }
        int len=v.size();
        /*cout<<"the vector\n";
        display(v);*/
        getPerm(v,sim);
        /*cout<<"after store\n";
        display(sim);*/
        set<vector<int>> newSet = {}; 
        if(oddCount!=0){
            /*for(int i=0;i<sim.size();i++){
                //sim[i].push_back(a);
                sim[i].insert(a);
            }*/
            /*for(auto x:sim){
                x.push_back(a);
            }*/
            for (auto v : sim) { 
                v.push_back(a);
                newSet.insert(v);
            }
            if(newSet.size()==0){
                newSet.insert({a});
            }
            sim = newSet;
        }
        //int len=sim.size();
        /*if(len%2!=0){
            len--;
        }*/
        /*for(int i=0;i<sim.size();i++){
            for(int j=len-1;j>=0;j++){
                //sim[i].push_back(sim[i][j]);
                sim[i].insert(sim[i][j]);
            }
        }*/
        newSet={};
        /*cout<<"1st sim\n";
        display(sim);*/
        for(auto x:sim){
            for(int j=len-1;j>=0;j--){
                //sim[i].push_back(sim[i][j]);
                x.push_back(x[j]);
            }
            newSet.insert(x);
        }
        sim=newSet;
        /*cout<<"2nd sim\n";
        display(sim);*/
        return;
    }
    void permOperator(int sz,set<vector<int>>&sim,vector<vector<int>>&v){
        for(auto x:v){
            set<vector<int>>s1;
            //cout<<"new\n";
            callArranger(s1,x,sz);
            //sim.insert(s1);
            for(auto y:s1){
                sim.insert(y);
            }
            /*cout<<"retCallArranger\n";
            display(s1);*/
        }
        return;
    }
    long long getNumFromVector(vector<int>&v){
        long long num=0;
        long long j=1;
        for(int i=v.size()-1;i>=0;i--){
            num+=v[i]*j;
            j*=10;
        }
        return num;
    }
    void getAllNums(set<vector<int>>&sim,vector<long long>&nums){
        int a=0;
        for(auto x:sim){
            //cout<<"vectors\n";
            //display(x);
            nums.push_back(getNumFromVector(x));
        }
        /*cout<<"nums\n";
        display(nums);*/
    }
    
    long long caller(long long n,int sz){
        vector<int>v;
        vector<vector<int>>res;
        set<vector<int>>sim;
        int sum=0,oddCount=0;
        for(int i=1;i<10;i++){
            if(i%2!=0 && oddCount==1)continue;
            v.push_back(i);
            if(i%2!=0)oddCount=1;
            sum+=i;
            divide(v,i+1,res,sum,sz,oddCount);
            if(i%2!=0){
                oddCount=0;
            }
            v.pop_back();
            sum-=i;
        }
        /*cout<<"res\n";
        display(res);*/
        //return 0;
        //vector<vector<int>>sim;
        permOperator(sz,sim,res);
        
        /*cout<<"final\n";
        display(sim);*/
        //return 0;
        vector<long long>nums;
        getAllNums(sim,nums);
        long long ans=2666888888886663;
        for(auto x:nums){
            if(x>n&&x<ans){
                ans=x;
            }
        }
        return ans;
    }
    long long specialPalindrome(long long n) {
        int sz=0;
        findLen(n,sz);
        long long ans=caller(n,sz);
        if(ans==2666888888886663){
            ans=caller(n,sz+1);
        }
        return ans;
    }
};

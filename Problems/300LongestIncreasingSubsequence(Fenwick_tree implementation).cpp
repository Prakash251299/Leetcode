class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            cout<<x[0]<<" ";
        }
        cout<<"\n";
    }
    void propagate(vector<vector<int>>&bit,int val,int j,int m){
        //if(j==0){return;}
        int temp=j;
        while(j<m){
            if(val<bit[j][0]){
                break;
            }
            
            if(val>=bit[j][0]){
            //if(val>=0){
                bit[j][0]=val;
                bit[j][1]=-1;
            }
            j+=(j&-j);
            if(j==temp)break;
        }
        return;
    }
    int lengthOfLIS(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]+=10000;
        }
        int m=*max_element(nums.begin(),nums.end());
        m++;
        vector<int>v=nums;
        int res=0;
        vector<vector<int>>bit(m,vector<int>(2,0));
        //cout<<"size:"<<bit.size()<<"\n";
        for(int i=0;i<nums.size();i++){
            //int diff=bit[v[i]][0];
            if(v[i]==0){
                bit[v[i]][0]=1;
                bit[v[i]][1]=1;
                res=max(res,1);
                continue;
            }
            if(bit[v[i]][1]==-1){
                bit[v[i]][0]+=1;
                bit[v[i]][1]=1;
            }
            int t=v[i]&(-v[i]);
            int p=v[i]-t;
            //cout<<p<<"\n";
            
            int j=p,maxi=0;
            int temp=0;
            while(j>=0){
                if(bit[j][0]>maxi){
                    maxi=bit[j][0];
                }
                j-=(j&-j);
                if(j==temp){break;}
            }
            /*if(bit[v[i]][1]==-1){
                if(maxi+1>bit[v[i]][0]){
                    bit[v[i]][0]=maxi+1;
                    bit[v[i]][1]=1;
                }
            }else{*/
                bit[v[i]][0]=max(maxi+1,bit[v[i]][0]);
            //}
            if(res<bit[v[i]][0]){
                res=bit[v[i]][0];
            }
            
            j=v[i];
            j+=(j&-j);
            propagate(bit,bit[v[i]][0],j,m);
            // display(bit);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findMajorityOneThird(vector<int>&v){
    int n = v.size();
    // int a1=v[0];
    // int a2=v[0];
    int a1=-1;
    int a2=-1;
    int c1=1;
    int c2=0;
    
    for(int i=1;i<v.size();i++){
        if(c1>0 && c2>0){
            if(a1==v[i]){
                c1++;continue;
            }
            if(a2==v[i]){
                c2++;continue;
            }
            c1--;c2--;
            continue;
        }
        if(c1==0&&c2==0){
            c1++;
            a1=v[i];
            continue;
        }
        if(c1==0){
            if(a2==v[i]){
                c2++;
            }else{
                a1 = v[i];
                c1++;
            }
            continue;
        }
        if(c2==0){
            if(a1==v[i]){
                c1++;
            }else{
                a2 = v[i];
                c2++;
            }
            continue;
        }
    }
    c1=0;c2=0;
    for(auto x:v){
        if(x==a1){c1++;}
        if(x==a2){c2++;}
    }
    vector<int> res;
    if(c1>n/3){
        res.push_back(a1);
    }
    if(c2>n/3 && a2!=a1){
        // cout<<c2<<"\n";
        res.push_back(a2);
    }
    
    // display(res);
    return res;
}
    vector<int> majorityElement(vector<int>& nums) {
        return findMajorityOneThird(nums);
    }
};

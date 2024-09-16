class Solution {
public:
    int hourToMinutes(string s){
        int r=0;
        r = (int(s[1]-'0')+int(s[0]-'0')*10)*60+int(s[3]-'0')*10+int(s[4]-'0');
        // cout<<r<<" ";
        return r;
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int>v(timePoints.size(),0);
        int i=0;
        for(auto x:timePoints){
            int t = hourToMinutes(x);
            v[i] = t;
            i++;
        }
        // display(v);
        sort(v.begin(),v.end(),greater<int>());
        int min=1500;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]-v[i+1]<min){
                min = v[i]-v[i+1];
            }
        }
        int t = 1440-v[0]+v[v.size()-1];
        if(t<min){
            min=t;
        }
        return min;
    }
};

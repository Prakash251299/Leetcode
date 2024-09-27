class MyCalendar {
public:
    vector<int>v;
    unordered_map<int,int>m;
    MyCalendar() {
        // pass;
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }

    int check(int s,int e,int a){
        // if(a<v.size()){
        //     return 0;
        // }
        // display(v);
        // cout<<"check for "<<s<<"\n";
        if(a-1<0){
            if(a<v.size() && e>v[a]){
                // cout<<"no1\n";
                return 0;
            }
            // cout<<"yes1\n";
            return 1;
        }else
        if(m[v[a-1]]>s){
            // cout<<"no2\n";
            return 0;
        }
        if(a<v.size() && e>v[a]){
            // cout<<"no\n";
            return 0;
        }
        // cout<<"yes2\n";
        return 1;
    }

    void display(unordered_map<int,int>m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
        cout<<"\n";
    }
    
    bool book(int start, int end) {
        int a = lower_bound(v.begin(), v.end(), start) - v.begin();
        if(v.size()==0){
            v.insert(v.begin()+a,start);
            m[start] = end;
            // display(v);
            return true;
        }
        if(a<v.size() and v[a]==start){
            // display(v);
            return false;
        }
        // v.push_back(start);
        // m[start] = end;
        // display(v);
        // cout<<a<<" - "<<v.size()<<"\n";
        int k = 0;
        // cout<<m[v[a-1]];
        k = check(start,end,a);
        if(k==1){
        // //     // v.push_back(start);
            v.insert(v.begin()+a,start);
            m[start] = end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

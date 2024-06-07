class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end(),greater<int>());
        map<int,int>m;
        map<int,int>m1;
        for(auto x:hand){
            ++m[x];
        }
        int count=0,prev=-1;

        while(m.size()!=0){
            prev=-1;
            count=0;
            m1 = m;
            // displayMap(m1);
            for(auto x:m1){
                if(count==groupSize){
                    count=0;
                    break;
                }
                if(x.first==prev){
                    continue;
                }
                if(prev>=0 && x.first-prev>1){
                    return false;
                }
                prev = x.first;
                --m[x.first];
                if(m[x.first]<=0){
                    m.erase(x.first);
                }
                count++;
            }
        }
        if(count==groupSize){
            return true;
        }
        return false;
    }
};

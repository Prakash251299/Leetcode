class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>v(n,0);
        for(auto x:bookings){
            for(int i=x[0];i<=x[1];i++){
                v[i-1]+=x[2];
            }
        }
        return v;
    }
};

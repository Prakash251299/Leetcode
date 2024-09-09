class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int t=0;
        map<vector<int>,int>m;
        for(auto x:obstacles){
            m[x]=1;
        }
        int x=0,y=0,dir=0,ma=0;
        for(auto a:commands){
            if(a==-2){
                dir=(dir+3)%4;
            }
            else if(a==-1){
                dir = (dir+1)%4;
            }
            if(a>0){
                int k = a;
                int newX=x;
                int newY=y;
                for(int i=1; i<=a; i++){
                    if(dir==0){
                        newY++;
                    }
                    if(dir==1){
                        newX++;
                    }
                    if(dir==2){
                        newY--;
                    }
                    if(dir==3){
                        newX--;
                    }
                    if(m[{newX,newY}]==1){
                        break;
                    }
                    x = newX, y=newY;
                }
                ma = max(ma, x*x+y*y);
            }
        }
        return ma;
    }
};

class Solution {
public:
    int ostaclePresent(int x,int y,unordered_map<string,int>m){
        string t = to_string(x)+"+"+to_string(y);
        if(m[t]==1){
            return 1;
        }
        // cout<<x<<" "<<y<<":"<<m[{x,y}]<<"\n";
        // if(m[{x,y}]==1){
        //     return 1;
        // }
        return 0;
    }

    int dist(int x,int y){
        int d = x*x+y*y;
        return d;
    }

    void show(unordered_map<string,int>m){
        for(auto x:m){
            cout<<x.first<<" "<<x.second<<"\n";
        }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int t=0;
        unordered_map<string,int>m;
        // vector<int>v(2,0);
        for(auto x:obstacles){
            string t = to_string(x[0])+"+"+to_string(x[1]);
            m[t]=1;
        }
        // show(m);
        // return 0;
        // cout<<m[{2,4}];
        int x=0,y=0,dir=1,ma=0,d=0;
        vector<vector<int>>direc = {{-1,0},{0,1},{1,0},{0,-1}}; 
        for(auto a:commands){
            if(a==-2){
                // move left
                // if(dir==0) dir = 3;
                // else dir--;
                dir=(dir+3)%4;
            }
            else if(a==-1){
                // move right
                dir = (dir+1)%4;
            }
            if(a>0){
                int k = a;
                for(int i=1; i<=k; i++){
                    int newX = x+direc[dir][0];
                    int newY = y+direc[dir][1];
                    
                    string key = to_string(newX)+"+"+to_string(newY);
                    if(m[key]==1){
                        break;
                    }
                    x = newX, y=newY;
                    ma = max(ma, x*x+y*y);
                }

                // switch(dir){
                // case 0:

                // // if(dir==0)
                // {
                //     t=y;
                //     for(int i=1;i<=a;i++){
                //         if(ostaclePresent(x,t+i,m)==1){
                //             break;
                //         }
                //         y++;
                //     }
                //     d = dist(x,y);
                //     if(d>max){
                //         max=d;
                //     };break;
                // }
                // // else
                // case 1:
                // // if(dir==1)
                // {
                //     t=x;
                //     for(int i=1;i<=a;i++){
                //         if(ostaclePresent(i+t,y,m)==1){
                //             break;
                //         }
                //         x++;
                //     }
                //     d = dist(x,y);
                //     if(d>max){
                //         max=d;
                //     };break;
                // }
                // case 2:
                // // }
                // // else
                // // if(dir==2)
                // {
                //     t=y;
                //     for(int i=1;i<=a;i++){
                //         if(ostaclePresent(x,t-i,m)==1){
                //             break;
                //         }
                //         y--;
                //     }
                //     d = dist(x,y);
                //     if(d>max){
                //         max=d;
                //     };break;
                // }
                // // else
                // case 3:
                // // if(dir==3)
                // {
                //     t=x;
                //     // cout<<"h"<<"\n";
                //     for(int i=1;i<=a;i++){
                //         if(ostaclePresent(t-i,y,m)==1){
                //             break;
                //         }
                //         x--;
                //     }
                //     // cout<<x<<" "<<y<<"\n";
                //     d = dist(x,y);
                //     if(d>max){
                //         max=d;
                //     };break;
                //     // default:break;
                // }}
            }
            // else{
            //     if(a==-1){
            //         dir=(dir+1)%4;
            //     }
            //     if(a==-2){
            //         dir=(dir+3)%4;
            //     }
            // }
            // cout<<x<<" "<<y<<"\n";
        }
        return ma;
    }
};

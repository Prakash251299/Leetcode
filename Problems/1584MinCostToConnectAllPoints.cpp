class Solution {
public:
   // void display(priority_queue<pair<int,vector<int>>>pq){
    void display(priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq){
        while(!pq.empty()){
            cout<<pq.top().first<<":["<<pq.top().second[0]<<","<<pq.top().second[1]<<"]"<<"\n";
            pq.pop();
        }
        return;
    }
    int manDist(vector<int>p1,vector<int>&p2){
        //cout<<"manDist ("<<p1[0]<<","<<p1[1]<<"),("<<p2[0]<<","<<p2[1]<<") = ";
  int a=p1[0]-p2[0];
  a<0?a=-1*a:a=a;
  int b=p1[1]-p2[1];
  b<0?b=-1*b:b=b;
        //cout<<a+b<<"\n";
  return a+b;
}

void getAllConnNodes(int&v,vector<vector<int>>&points, //priority_queue<pair<int,vector<int>>>&pq, 
                     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> &pq, vector<int>&visited){
    //vector<int>v=pq.top().second;
  for(int i=0;i<points.size();i++){
    if(visited[i]==1){ continue;}
    int dist= manDist(points[v],points[i]);
    pq.push({dist,i});
    //visited[points[i]]=1;
  }
  return;
}

    int minCostConnectPoints(vector<vector<int>>& points) {
  //vector<vector<int>>points({{2,-3},{-17,-8},{13,8},{-17,-15}});
  //priority_queue<pair<int,vector<int>>>pq;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  //map<vector<int>,int>visited;
  vector<int>visited(points.size(),0);
  pq.push({0,0});
 // visited[points[0]]=1;
  //cout<<pq.top().first<<"\n";
  int c=0, count=0;
  for(int i=0;i<points.size();i++){
   // while(!pq.empty() && visited[i]==1){
    while(!pq.empty() && visited[pq.top().second]==1){
      pq.pop();
    }
    if(pq.empty()){continue;}
    /*cout<<pq.top().second[0]<<",";
    cout<<pq.top().second[1]<<"\n";
    cout<<pq.top().first<<"\n";*/
    count+=pq.top().first;
    if(c==points.size()){break;}
    visited[pq.top().second]=1;c+=1;
    int v=pq.top().second;
    pq.pop();
    getAllConnNodes(v,points,pq,visited);
    //cout<<"pq print\n";
      //display(pq);
  }
  //cout<<count;
  return count;
}
};

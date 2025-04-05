class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int b = bricks,l = ladders,c=0;
        int prev=heights[0];
        priority_queue<int>heap;
        for(int i=1;i<heights.size();i++){
            int diff = heights[i]-prev;
            if(diff>0){
                if(b>=diff){
                    heap.push(diff);
                    b-=diff;
                }else{
                    if(l>0){
                        heap.push(diff);
                        b-=diff;
                        int top = heap.top();
                        heap.pop();
                        l--;
                        b+=top;
                    }else{
                        return c;
                    }
                }
            }
            c++;
            prev = heights[i];
        }
        return c;
    }
};

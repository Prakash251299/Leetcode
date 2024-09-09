/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void display(vector<vector<int>>v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m,vector<int>(n,-1));
        int grid = m*n,c=0,i=0,j=0,d=0;
        // display(v);
        // if(head==NULL){
        //     return v;
        // }
        // v[i][3]=0;
        // cout<<m;
        // cout<<n;
        // return v;
        vector<int>ic(2,0); // i conatiner
        vector<int>jc(2,0); // j conatiner
        ic[1]=m-1;
        jc[1]=n-1;
        while(1){
            if(head==NULL || c>=grid){
                break;
            }
            v[i][j]=head->val;
            head=head->next;
            c++;
            if(d==0 && j+1>jc[1]){
                d=1;i++;++ic[0];
                continue;
            }
            if(d==0 && j+1<=jc[1]){
                j++;
            }
            if(d==1 && i+1>ic[1]){
                d=2;j--;--jc[1];
                continue;
            }
            if(d==1 && i+1<=ic[1]){
                i++;
            }
            if(d==2 && j-1<jc[0]){
                d=3;i--;--ic[1];
                continue;
            }
            if(d==2 && j-1>=jc[0]){
                j--;
            }
            if(d==3 && i-1<ic[0]){
                d=0;j++;++jc[0];
                continue;
            }
            if(d==3 && i-1>=ic[0]){
                i--;
            }
            // head = head->next;
            // c++;
        }
        display(v);
        return v;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void fun(Node* node, Node* curr, map<Node*,Node*>&visited){
        if(node==NULL){
            return;
        }
        vector<Node*>v;
        
        for(auto x:node->neighbors){
            if(visited[x]==NULL){
                Node* newNode = new Node(x->val);
                v.push_back(newNode);
                visited[x]=newNode;
                fun(x,newNode,visited);
                // cout<<newNode->val<<" ";
                // cout<<x->val<<"\n";
            }else{
                v.push_back(visited[x]);
            }
        }
        curr->neighbors = v;
        return;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        Node* q = new Node(node->val);
        map<Node*,Node*>visited;
        visited[node]=q;
        fun(node,q,visited);
        // visited.clear();
        // display(q,visited);
        return q;
    }
};

class Solution {
public:
    struct Trie{
        Trie* child[26] = {};
        int prefix = 0;
        // int counter[26];
        // Trie(){
        //     prefix = 0;
        // }
    };

    int search(Trie* root,string s){
        Trie* curr = root;
        int sum=0;
        for(auto c:s){
            if(curr->child[c-'a']==NULL){
                // cout<<"\n";
                return sum;
            }
            curr = curr->child[c-'a'];
            sum += curr->prefix;
        }
        return sum;
    }

    void insert(Trie* root,string s){
        Trie* curr = root;
        // cout<<s<<" ";
        // int i=0;
        for(auto c:s){
            if(curr->child[c-'a']==NULL){
                Trie* newNode = new Trie();
                curr->child[c-'a'] = newNode;
            }
            curr = curr->child[c-'a'];
            curr->prefix++;
        }
        return;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>res(words.size(),0);
        Trie* root=new Trie();
        for(auto x:words){
            insert(root,x);
        }
        // cout<<"inserted\n";
        int i=0;
        for(auto x:words){
            res[i] = search(root,x);
            i++;
        }
        return res;
    }
};

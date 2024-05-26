class ATM {
    vector<long> v;
public:
    ATM() {
        for(int i=0;i<5;i++){
            v.push_back(0);
        }
    }
    
    void deposit(vector<int> banknotesCount) {
        // if(v.size)
        for(int i=0;i<5;i++){
            v[i] = v[i] + banknotesCount[i];
        }
        // this->v = banknotesCount;
    }
    
    vector<int> withdraw(int amount) {
        vector<long>va=v;
        vector<int>usedNotes;
        vector<int>notes;
        notes.push_back(20);
        notes.push_back(50);
        notes.push_back(100);
        notes.push_back(200);
        notes.push_back(500);
        for(int i=0;i<5;i++){
            usedNotes.push_back(0);
        }
        int i=4,found=0;
        for(;i>=0;i--){
            int temp = amount/notes[i];
            if(temp<=va[i]){
                va[i]-=temp;
                amount-=notes[i]*temp;
                usedNotes[i]+=temp;
            }else{
                temp=v[i];
                va[i]-=temp;
                amount-=notes[i]*temp;
                usedNotes[i]+=temp;
            }

            // cout<<amount<<" ";
            if(amount==0){
                found=1;
                break;
            }

        }
        if(found==0){
            usedNotes.clear();
            usedNotes.push_back(-1);
        }else{
            for(int i=0;i<5;i++){
                v[i]-=usedNotes[i];
            }
        }
        
        return usedNotes;
    }
    
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
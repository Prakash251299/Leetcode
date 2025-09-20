class Solution {
public:
    void numToBin(long long n,string &bin){
        if(n==0){bin="0";return;}
        while(n>0){
            bin+=char(n%2+int('0'));
            n/=2;
        }
        reverse(bin.begin(),bin.end());
        return;
    }
    long long binToNum(string &bin){
        long long mult=0,n=0;
        for(long long i=bin.size()-1;i>=0;i--){
            if(bin[i]=='1'){
                n+=pow(2,mult);
            }
            mult++;
        }
        //cout<<n<<"\n";
        return n;
    }
    int getBinPalCountSmaller(int n){
        int c=0;
        if(n==0)return 1;
        while(1){
            if(n==1){
                c+=2;
                break;
            }
            if(n==2){
                c+=3;break;
            }
            c+=pow(2,(n-1)/2);
            n--;
        }
        cout<<c<<"\n";
        return c;
    }
    int countBinaryPalindromes(long long n) {
        if(n==0)return 1;
        string s="";
        numToBin(n,s);
        //cout<<s<<"\n";
        //cout<<binToNum(s)<<"\n";
        int binSz=s.size();
        string half="";
        for(int i=0;i<(s.size())/2;i++){
            half+=s[i];
        }
        string nextHalf=half;
        string mid="";
        reverse(nextHalf.begin(),nextHalf.end());
        if(s.size()%2==1){
            mid=s[s.size()/2];
        }
        string palStr=half+mid+nextHalf;
        //cout<<palStr<<"\n";
        long long n2=binToNum(palStr);
        int extra=0;
        if(n2>n){
            extra=1;
        }
        //cout<<n2<<" "<<extra<<"\n";
        half+=mid;
        half[0]=0;
        int count=0;
        /*for(int i=half.size();i>0;i--){
            if(half[i])
        }*/
        count+=binToNum(half)+1-extra;
        //cout<<count<<"\n";
        count+=getBinPalCountSmaller(binSz-1);
        return count;
    }
};

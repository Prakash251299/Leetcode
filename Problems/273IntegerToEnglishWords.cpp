class Solution {
public:
    string oneDigit(int n){
        if(n==1){
            return "One ";
        }
        if(n==2){
            return "Two ";
        }
        if(n==3){
            return "Three ";
        }
        if(n==4){
            return "Four ";
        }
        if(n==5){
            return "Five ";
        }
        if(n==6){
            return "Six ";
        }
        if(n==7){
            return "Seven ";
        }
        if(n==8){
            return "Eight ";
        }
        if(n==9){
            return "Nine ";
        }
        if(n==10){
            return "Ten ";
        }
        if(n==11){
            return "Eleven ";
        }
        if(n==12){
            return "Twelve ";
        }
        if(n==13){
            return "Thirteen ";
        }
        if(n==14){
            return "Fourteen ";
        }
        if(n==15){
            return "Fifteen ";
        }
        if(n==16){
            return "Sixteen ";
        }
        if(n==17){
            return "Seventeen ";
        }
        if(n==18){
            return "Eighteen ";
        }
        if(n==19){
            return "Nineteen ";
        }
        return "";
    }

    string twoDigit(int n){
        if(n==2){
            return "Twenty ";
        }
        if(n==3){
            return "Thirty ";
        }
        if(n==4){
            return "Forty ";
        }
        if(n==5){
            return "Fifty ";
        }
        if(n==6){
            return "Sixty ";
        }
        if(n==7){
            return "Seventy ";
        }
        if(n==8){
            return "Eighty ";
        }
        if(n==9){
            return "Ninety ";
        }
        return "";
    }

    string chunkName(int a){
        if(a==1){
            return "Thousand ";
        }
        if(a==2){
            return "Million ";
        }
        if(a==3){
            return "Billion ";
        }
        if(a==4){
            return "Trillion ";
        }
        return "";
    }

    string numberToWords(int num) {
        string res="";
        int a=0,b=0,c=0;
        string tempStr="";
        int n = num;
        if(n==0){
            return "Zero";
        }
        while(1){
            if(n==0){
                break;
            }
            tempStr="";
            int t=n;
            a=t%1000;
            b=t%100;
            t = (a-b)/100;
            if(t!=0){
                tempStr = oneDigit(t)+"Hundred ";
            }
            t=n;
            a = t%100;
            b = t%10;
            t = (a-b)/10;
            if(t<2 and t!=0){
                t = n;
                t = t%100;
                tempStr += oneDigit(t);
            }
            else{
                tempStr += twoDigit(t);
                tempStr += oneDigit(b);
            }
            n=n/1000;
            if(tempStr!=""){
                res=tempStr+chunkName(c)+res;
            }
            tempStr="";
            c++;
        }
        // removing last etra space
        res.erase(remove(res.end()-1, res.end()-1, ' '), res.end());
        return res;
    }
};

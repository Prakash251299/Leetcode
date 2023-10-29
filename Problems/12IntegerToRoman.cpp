class Solution {
public:
    string fun(int a){
        if(a==0){
            return "";
        }
        string s="";
        int f=0;
        if(a%1000==0){
            f = a/1000;
            for(int i=0;i<f;i++){
                s = s+"M";
            }
            return s;
        }
        if(a==900){
            return "CM";
        }
        if(a>500 and a<900){
            s=s+"D";
            int f = (a-500)/100;
            for(int i=0;i<f;i++){
                s = s+"C";
            }
            return s;
        }
        if(a==500){
            return "D";
        }
        if(a==400){
            return "CD";
        }
        if(a>100 and a<400){
            f = (a-100)/100;
            s = s+"C";
            for(int i=0;i<f;i++){
                s = s+"C";
            }
            return s;
        }
        if(a==100){
            return "C";
        }
        if(a==90){
            return "XC";
        }
        if(a>50 and a<90){
            f = (a-50)/10;
            s = s+"L";
            for(int i=0;i<f;i++){
                s = s+"X";
            }
            return s;
        }
        if(a==50){
            return "L";
        }
        if(a==40){
            return "XL";
        }
        if(a>10 and a<40){
            f = (a-10)/10;
            s = s+"X";
            for(int i=0;i<f;i++){
                s = s+"X";
            }
            return s;
        }
        if(a==10){
            return "X";
        }
        if(a==9){
            return "IX";
        }
        if(a>5 and a<9){
            f = a-5;
            s = s+"V";
            for(int i=0;i<f;i++){
                s = s+"I";
            }
            return s;
        }
        if(a==5){
            return "V";
        }
        if(a==4){
            return "IV";
        }
        if(a==3){
            return "III";
        }
        if(a==2){
            return "II";
        }
        if(a==1){
            return "I";
        }
        
        return "";
    }
    
    string roman(int n){
        string s="";
        int i=1;
        for(;;i++){
            if(n==0){
                break;
            }
            int p=pow(10,i);
            int d = n%p;
            s = fun(d)+s;
            n = n-d;
        }
        return s;
    }
    
    string intToRoman(int num) {
        return roman(num);
    }
};

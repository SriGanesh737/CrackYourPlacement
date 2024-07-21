class Solution {
public:

    string code(int digit, char ch1 = 'I', char ch2='V', char ch3='X'){
        string ans = "";
        if(digit<=3){
            while(digit--) ans+=ch1;
            return ans;
        }
        else if(digit == 4){
            ans+=ch1;
            ans+=ch2;
            return ans;
        }
        else if(digit == 9){
            ans += ch1;
            ans += ch3;
            return ans;
        }
        else{
            ans += ch2;
            digit-=5;
            while(digit--) ans+=ch1;
            return ans;
        }
    }

    
    string intToRoman(int num) {
        
        string ans = "";
        int pos = 0;
        vector<int>v;
        while(num){
            int k = num % 10;
            v.push_back(k);
            num/=10;
        }

        reverse(v.begin(),v.end());



        for(int i = 0;i<v.size();i++){
            int pos = v.size() - i;

            if(pos == 1) ans += code(v[i],'I','V','X');
            else if(pos == 2) ans += code(v[i],'X','L','C');
            else if(pos == 3) ans += code(v[i],'C','D','M');
            else if(pos == 4) ans += code(v[i],'M','*','#');
        }
        return ans;
    }
};
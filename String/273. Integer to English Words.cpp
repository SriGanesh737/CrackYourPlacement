class Solution {
public:

    string func(int num){
        // num should be only 3 digits
        map<int,string>mp = {
            {1,"One"},
            {2,"Two"},
            {3,"Three"},
            {4,"Four"},
            {5,"Five"},
            {6,"Six"},
            {7,"Seven"},
            {8,"Eight"},
            {9,"Nine"},
            {10,"Ten"},
            {11,"Eleven"},
            {12,"Twelve"},
            {13,"Thirteen"},
            {14,"Fourteen"},
            {15,"Fifteen"},
            {16,"Sixteen"},
            {17,"Seventeen"},
            {18,"Eighteen"},
            {19,"Nineteen"},
            {20,"Twenty"},
            {30,"Thirty"},
            {40,"Forty"},
            {50,"Fifty"},
            {60,"Sixty"},
            {70,"Seventy"},
            {80,"Eighty"},
            {90,"Ninety"},
            {100,"Hundred"},
        };

        string ans = "";
        if(num/100) {
            ans += mp[num/100];
            ans += " Hundred ";
        }
        if((num%100)<20){
            ans += mp[num%100];
        }
        else{
            ans += mp[(num/10)%10*10];
            if(num % 10) {
                ans +=" ";
                ans += mp[num%10];
            }
        }

        if(ans!="" && ans.back()==' ') ans.pop_back();
        return ans;
    }
    string numberToWords(int num) {

        if(num==0) return "Zero";

        stack<string>st;
        string ans = "";

        while(num){
            string temp = func(num%1000);
            st.push(temp);
            num /= 1000;
        }

        map<int,string>keys = {
            {1," Thousand "},
            {2," Million "},
            {3, " Billion "},
            {4, " Trillion "}
        };

        while(!st.empty()){
            int pos = st.size();
            ans += st.top();
            if(pos>1 && st.top()!="")
                ans += keys[pos-1];
            st.pop();
        }
        if(ans.back()==' ') ans.pop_back();
        return ans;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int bit = 0;
        string ans ="";
        int n1 = a.length(), n2 = b.length();
        int i = n1-1, j = n2-1;
        while(i>=0 && j>=0){
            int bit_a = a[i]-'0';
            int bit_b = b[j]-'0';
            bit = (bit_a + bit_b + carry)%2;
            carry = (bit_a+bit_b+carry)/2;
            ans+=('0'+bit);
            i--;
            j--;
        }

        while(i>=0){
            int bit_a = a[i]-'0';
            int sum = (bit_a+carry);
            carry = sum/2;
            ans+=(sum%2+'0');
            i--;
        }

        while(j>=0){
            int bit_b = b[j]-'0';
            int sum = (bit_b+carry);
            carry = sum/2;
            ans+=(sum%2+'0');
            j--;
        }

        if(carry==1) ans+=('1');

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
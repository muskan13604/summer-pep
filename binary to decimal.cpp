class Solution {
  public:
    int binaryToDecimal(string& b) {
        // code here
         int ans = 0;

        for (char ch : b) {
            ans = ans * 2 ;
            ans = ans + (ch - '0');
        }

        return ans;
    }
    
};
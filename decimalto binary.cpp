class Solution {
public:
    string decToBinary(int n) {
        string ans = "";
        if (n == 0) return "0";

        while (n > 0 ) {
            ans += (n % 2) + '0';
            n /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
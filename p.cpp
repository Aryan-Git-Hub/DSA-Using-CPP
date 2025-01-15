class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        if (x > 0) {
            int rn = 0;
            while (temp > 0) {
                int ld = temp % 10;
                rn = rn * 10 + ld;
                temp = temp / 10;
            }
            if (rn == x) return true;
        }
        return false;
    }
};
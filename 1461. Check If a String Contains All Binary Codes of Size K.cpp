/* PROBLEM STATEMENT

Given a binary string s and an integer k.

Return True if every binary code of length k is a substring of s. Otherwise, return False.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "00110", k = 2
Output: true
Example 3:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 4:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.
Example 5:

Input: s = "0000000001011100", k = 4
Output: false
 

Constraints:

1 <= s.length <= 5 * 10^5
s consists of 0's and 1's only.
1 <= k <= 20

*/

// SOLUTION
// Rolling Hash
// O(n), here n is the length of the given binary string
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > 15) return false;
        int n = s.size() - k;
        int num_codes = 1 << k;
        vector<bool> codes(num_codes, false);
        int code = stoi(s.substr(0, k), 0, 2);
        int mask = ~(1 << (k - 1));
        int count = 0;
        for (int i = 0; i <= n; ++i) {
            if (!codes[code]) {
                codes[code] = true;
                if (num_codes == ++count) return true;
            }
            if (i < n) {
                code &= mask;
                code = (code << 1) | (s[i + k] - '0');
            }
        }
        return false;
    }
};




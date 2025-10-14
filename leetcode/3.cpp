#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        vector<int> last(256, -1);
        int start = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (last[(unsigned char)s[i]] >= start) {
                start = last[(unsigned char)s[i]] + 1;
            }
            last[(unsigned char)s[i]] = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
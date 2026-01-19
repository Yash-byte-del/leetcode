class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int n = s.size();
        
        int l = 0;
        int maxlen = 0;

        for (int r = 0; r < n; r++) {
            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            hash[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

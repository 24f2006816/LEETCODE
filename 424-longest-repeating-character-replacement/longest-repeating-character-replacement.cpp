class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Add new character to window
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            // Window size - max frequency = characters to replace
            int windowLen = right - left + 1;
            
            // If invalid, shrink window from left
            if (windowLen - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
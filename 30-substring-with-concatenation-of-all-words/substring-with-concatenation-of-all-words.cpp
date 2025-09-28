 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if ((int)s.size() < totalLen) return result;

        // Frequency map of words
        unordered_map<string, int> wordMap;
        for (string& w : words) {
            wordMap[w]++;
        }

        // Try all possible offsets (0 to wordLen-1)
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> windowMap;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordMap.find(word) != wordMap.end()) {
                    windowMap[word]++;
                    count++;

                    // If more than expected, shrink from left
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If exact match of all words
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // reset window
                    windowMap.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};

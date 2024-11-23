//TC: O(n) + O(k * m * logn)
//MC: O(n)
// n is the length of string, m is the average word length, k is the no of words

class SubsequenceChecker {
private:
    unordered_map<char, vector<int>> charIndices;

public:
    SubsequenceChecker(const string& s) {
        for (int i = 0; i < s.size(); ++i) {
            charIndices[s[i]].push_back(i);
        }
    }

    bool isSubsequence(const string& word) {
        int prevIndex = -1;
        for (char c : word) {
            if (charIndices.find(c) == charIndices.end()) {
                return false;
            }
            const vector<int>& indices = charIndices[c];
            auto it = upper_bound(indices.begin(), indices.end(), prevIndex);
            if (it == indices.end()) {
                return false;
            }
            prevIndex = *it;
        }
        return true;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        SubsequenceChecker checker(s);
        int count = 0;
        for (const string& word : words) {
            if (checker.isSubsequence(word)) {
                ++count;
            }
        }
        return count;
    }
};

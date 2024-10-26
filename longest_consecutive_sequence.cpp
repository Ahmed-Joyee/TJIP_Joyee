class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int longest = 0, length;

        for(int num : nums) {
            if(numset.find(num - 1) == numset.end()) {
                length = 1;
                while(numset.find(num + length) != numset.end())
                    length++;
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

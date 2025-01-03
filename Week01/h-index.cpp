//TC: O(N log N)
//MC: O(1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), h;
      
        for (int i = 0; i < n; ++i) {
            h = n - i;  
            if (citations[i] >= h) return h;
        }
        return 0;
    }
};

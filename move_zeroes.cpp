//TC: O(N)
//MC: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero = 0;
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0) nums[non_zero++] = nums[i];
        
        for (int i = non_zero; i < nums.size(); i++)
            nums[i] = 0;
    }
};

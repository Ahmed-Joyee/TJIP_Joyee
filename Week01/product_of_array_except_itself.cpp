// couldn't solve it without the division operation in O(n)

//TC: O(N)
//MC: O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int count_zero = 0, product = 1;

        for(int num : nums) {
            if(num == 0) count_zero++;
            else product *= num;
        }

        if(count_zero > 1) {
            return vector<int> (nums.size(), 0);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(count_zero > 0)
                result[i] = (nums[i] == 0) ? product : 0;
            else result[i] = product / nums[i];
        }
        return result;
    }
};

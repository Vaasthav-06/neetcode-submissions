class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN; // Start with the smallest possible integer
        int left = 1;
        int right = 1;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the previous cumulative product became 0, reset it to 1 
            // to start calculating a fresh subarray.
            if (left == 0) left = 1;
            if (right == 0) right = 1;
            
            // Multiply the current elements from front and back
            left *= nums[i];
            right *= nums[n - i - 1];
            
            // Update the running maximum
            ans = max({ans, left, right});
        }
        
        return ans;
    }
};
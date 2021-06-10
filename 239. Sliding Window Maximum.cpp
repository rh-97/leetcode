// Monotonic Queue
// O(n)


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> dq;
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            
            if (!dq.empty() and dq.front() == i - k) dq.pop_front();
            
            while (!dq.empty() and nums[dq.back()] <= nums[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};



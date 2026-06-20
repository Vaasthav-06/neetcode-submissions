class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto it : nums) {
            pq.push(it);//O(n).
        }

        while (pq.size() > k) {
            pq.pop(); // TC((n - k). logn).
        }
    }

    int add(int val) {
        pq.push(val);
        int size = pq.size();

        if (size > k) {
            pq.pop();
        }
        int ans = pq.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
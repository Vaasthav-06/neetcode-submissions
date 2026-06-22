class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;

        vector<int> chars(26);

        for (int i = 0; i < tasks.size(); i++) {
            chars[tasks[i] - 'A']++;
        }

        for (auto it : chars) {
            if (it > 0) pq.push(it);
        }

        queue<pair<int, int>> q;

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int curr_max = pq.top();
                pq.pop();
                if (curr_max - 1 != 0) q.push({curr_max - 1, time + n});
            }

            if (!q.empty()) {
                if (q.front().second == time) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }
        }
        return time;
    }
};

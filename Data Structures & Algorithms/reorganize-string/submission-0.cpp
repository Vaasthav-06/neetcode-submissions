class Solution {
   public:
    string reorganizeString(string s) {
        vector<int> v(26);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                pq.push({v[i], i + 'a'});
            }
        }
        queue<pair<int, pair<int, char>>> q;

        string ans = "";
        int cnt = 0;
        while (!pq.empty() || !q.empty()) {
            if (!q.empty()) {
                if (q.front().first == cnt) {
                    pq.push(q.front().second);
                    q.pop();
                }
            }

            if(pq.empty()) return "";

            if (!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                int freq = it.first;
                char c = it.second;

                ans += c;
                freq--;

                if (freq != 0) {
                    q.push({cnt + 2, {freq, c}});
                }
            }

            cnt++;
        }

        return ans;
    }
};
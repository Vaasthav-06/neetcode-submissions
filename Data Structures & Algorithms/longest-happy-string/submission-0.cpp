#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a != 0) pq.push({a, 'a'});
        if (b != 0) pq.push({b, 'b'});
        if (c != 0) pq.push({c, 'c'});

        string res = "";
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            char ch = it.second;

            if (res.size() > 1 && res[res.size()-2] == res[res.size()-1] && res[res.size()-1] == ch) {
                if (pq.empty())
                    return res;
                else {
                    auto second_it = pq.top();
                    pq.pop();

                    pq.push(it);       // Push the 1st element back
                    it = second_it;    // Swap 'it' to be the 2nd element
                    ch = it.second;    // UPDATE 'ch' so the append logic uses the new character
                }
            } 
            
            // REMOVED 'else': Now, whether it's the normal 1st character 
            // or the swapped 2nd character, they both fall through to here!
            res += ch;
            int freq = it.first;
            freq--;

            if (freq != 0) pq.push({freq, ch});
        }
        
        return res;
    }
};
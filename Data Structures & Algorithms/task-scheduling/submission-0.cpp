class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task: tasks) {
            freq[task - 'A'] ++;
        }

        priority_queue<int> pq;
        for( int f : freq) {
            if(f > 0) {
                pq.push(f);    
            }
        }

        
        queue<pair<int, int>> cool_down;

        int time = 0;

        while(!pq.empty() || !cool_down.empty()) {
            if(!cool_down.empty() && cool_down.front().second == time) {
                pq.push(cool_down.front().first);
                cool_down.pop();
            }

            if (!pq.empty()) {
                int remaining = pq.top();
                pq.pop();
                remaining --;

                if(remaining > 0) {
                    cool_down.push({remaining, time + n + 1});
                }
            }

            time ++;
        }

        return time;
    }
};

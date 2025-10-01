class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int x : nums) ++freq[x];

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& kv : freq) buckets[kv.second].push_back(kv.first);

        vector<int> res;
        res.reserve(k);
        for (int c = (int)nums.size(); c >= 1 && (int)res.size() < k; --c) {
            for (int v : buckets[c]) {
                res.push_back(v);
                if ((int)res.size() == k) return res;
            }
        }
        return res;
    }
};

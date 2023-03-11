class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<int> dp;
    for (auto p : envelopes) {
        auto it = lower_bound(dp.begin(), dp.end(), p[1]);
        if (it == dp.end())
            dp.push_back(p[1]);
        else
            *it = p[1];
    }

    return dp.size();
}
};



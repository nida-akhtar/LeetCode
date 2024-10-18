class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    });
    set<int> availableDays;
    int maxEndDay = 0;
    for (const auto& event : events) {
        maxEndDay =  max (maxEndDay, event[1]);
    }
    for (int day =1; day<= maxEndDay; ++day){
        availableDays.insert(day);
    }
    int count=0;
    for (const auto& event : events)
    {
        auto it = availableDays.lower_bound(event[0]);
        if (it != availableDays.end() && *it <= event[1])
        {
            availableDays.erase(it);
            ++count;
                }        }
                return count;
    }
};
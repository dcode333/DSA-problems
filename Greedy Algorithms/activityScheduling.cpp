#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> activities = {{10, 100}, {15, 30}, {50, 60}};

    sort(begin(activities), end(activities),
         [](pair<int, int> const &a, pair<int, int> const &b)
         { return a.second < b.second; });

    int maxActivites = 0;
    int lastTime = activities[0].second;
    if (activities[1].second >= lastTime)
        maxActivites++;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].first >= lastTime)
        {
            maxActivites++;
            lastTime = activities[i].second;
        }
    }

    cout << maxActivites;

    return 0;
}

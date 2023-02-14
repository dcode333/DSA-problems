#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double ratio1 = p1.first / p1.second;
    double ratio2 = p2.first / p2.second;

    return ratio1 > ratio2;
}
int main()
{
    vector<pair<int, int>> activities = {{21, 7}, {24, 4}, {12, 6}, {40, 5}, {30, 6}};

    sort(begin(activities), end(activities), compare);
    int knapSack = 0, knapsackRange = 0;
    int knapSackWeight = 20;

    for (int i = 0; i < activities.size(); i++)
    {
        if (knapsackRange + activities[i].second <= knapSackWeight)
        {
            knapSack += activities[i].first;
            knapsackRange += activities[i].second;
        }
    }

    cout << knapSack;

    return 0;
}

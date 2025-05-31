#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};

// Comparator to sort activities by finish time
    bool activityCompare(Activity s1, Activity s2) {
    return (s1.finish < s2.finish); 
}

void printMaxActivities(vector<Activity>& activities) {
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected activities: ";

    // The first activity is always selected
    int lastSelected = 0;
    cout << "(" << activities[lastSelected].start << ", " << activities[lastSelected].finish << ") ";

    // Consider the rest of the activities
    for (int i = 1; i < activities.size(); i++) {
        // If this activity's start time is greater than or equal to the finish time of the last selected activity, select it
        if (activities[i].start >= activities[lastSelected].finish) {
        cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
        lastSelected = i;
        }
    }
cout << endl;
}

int main() {
    vector<Activity> activities = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    printMaxActivities(activities);
    return 0;
}
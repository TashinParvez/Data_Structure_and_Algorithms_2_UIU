
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
#define sp " " // space
#define setDec(x) fixed << setprecision(x)
#define len(s) s.length()
#define deb(n) cout << "Tashin   " << #n << " = " << n << endl; // debug code

using namespace std;

typedef struct Activities /// Container
{
    string actNo;
    int startTime;
    int endTime;
} Activity;

bool compare(Activity a, Activity b) /// Comperator
{
    return a.endTime < b.endTime;
}

int activitySelection(vector<Activity> activity)
{
    if (activity.size() == 0)
        return 0;

    int taskTaken_Counter = 1; /// always picked first task
    int freeTime = activity[0].endTime;
    cout << nl << "Activity Picked :  " << activity[0].actNo << " ";

    for (int i = 1; i < activity.size(); i++)
    {
        if (activity[i].startTime >= freeTime)
        {
            cout << activity[i].actNo << " ";
            taskTaken_Counter++;
            freeTime = activity[i].endTime;
        }
    }
    return taskTaken_Counter;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<Activity> activity(n);
    for (int i = 0; i < n; i++)
    {
        getchar();
        // cin.ignore(); /// similar as getchar();

        cin >> activity[i].actNo;
        cin >> activity[i].startTime;
        cin >> activity[i].endTime;
    }

    sort(activity.begin(), activity.end(), compare);

    int numberOftask = activitySelection(activity);

    cout << nl << "Num of tasks: " << numberOftask << nl;

    CRACKED;
}

/*
8

a1 1 3
a2 0 4
a3 1 2
a4 4 6
a5 2 9
a6 5 8
a7 3 5
a8 4 5


ans: 3

*/
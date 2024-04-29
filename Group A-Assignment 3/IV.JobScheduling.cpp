#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

struct Job
{
    int deadline;
    int profit;
    int index;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void job_scheduling(Job arr[], int n)
{
    // Sort job array based on decreasing profit
    sort(arr, arr + n, compare);

    int result[n];
    bool slot[n];
    memset(slot, false, sizeof(slot));

    // Fill slots
    for (int i = 0; i < n; i++)
    {
        // Find available slot before the deadline
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = arr[i].index;
                slot[j] = true;
                break;
            }
        }
    }

    // Print the scheduled jobs
    cout << "Scheduled Jobs:\n";
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
            cout << "Job " << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter deadline and profit for each job:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].deadline >> arr[i].profit;
        arr[i].index = i + 1;
    }

    job_scheduling(arr, n);

    return 0;
}

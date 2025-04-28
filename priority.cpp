// C++ implementation for priority based scheduling.
// April 27 2025
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int at, bt, ct, tat, wt, rt, id, pri;
};

int main()
{
    int n;
    cout << "enter the number of processes:\n";
    cin >> n;

    vector<process> v(n);

    for (int i = 0; i < n; i++)
    {
        cout << "enter id: at and bt and priority\n";
        cin >> v[i].id >> v[i].at >> v[i].bt >> v[i].pri;
    }

    // considering larger value as higher priority.

    int time = 0;
    int cnt = 0;
    vector<bool> complete(n, false);

    while (cnt < n)
    {
        int prit = -1e9;
        int idx = -1;

        for (int i = 0; i < n; i++)
        {
            if (v[i].at <= time && !complete[i])
            {
                if (v[i].pri > prit)
                {
                    prit = v[i].pri;
                    idx = i;
                }
                else if (v[i].pri == prit)
                {
                    if (v[i].at < v[idx].at)
                    {
                        idx = i;
                    }
                }
            }
        }
        if (idx == -1)
        {
            time++;
        }
        else
        {
            v[idx].rt = time - v[idx].at;
            time += v[idx].bt;
            v[idx].ct = time;
            v[idx].tat = v[idx].ct - v[idx].at;
            v[idx].wt = v[idx].tat - v[idx].bt;
            cnt++;
            complete[idx] = true;
        }
    }

    cout << "P.Id. \t A.T\t B.T\tPri.\t C.T\t T.A.T\t W.T\t R.T\n";

    for (int i = 0; i < n; i++)
    {
        cout << v[i].id << "\t" << v[i].at << "\t" << v[i].bt << "\t"<< v[i].pri << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << "\t" << v[i].rt << endl;
    }

    return 0;
}
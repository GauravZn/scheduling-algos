// C++ implementation of shortest remaining time first (SRTF) or SJF + preamption.
// April 27 2025
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int at, bt, ct, tat, wt, rt, id, rem;
};

int main()
{
    int n;
    cout << "enter the number of processes:\n";
    cin >> n;

    vector<process> v(n);

    for (int i = 0; i < n; i++)
    {
        cout << "enter id: at and bt\n";
        cin >> v[i].id >> v[i].at >> v[i].bt;
        v[i].rem = v[i].bt;
    }

    int cnt = 0;
    vector<bool> complete(n, false);
    int time = 0;

    while (cnt < n)
    {
        int mini = 1e9;
        int idx = -1;

        for (int i = 0; i < n; i++)
        {
            if (time >= v[i].at && !complete[i])
            {
                if (v[i].rem < mini)
                {
                    mini = v[i].rem;
                    idx = i;
                }
                else if (v[i].rem == mini)
                {
                    if (v[i].at < v[idx].at)
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            if (v[idx].rem == v[idx].bt)
            {
                v[idx].rt = time - v[idx].at;
            }

            v[idx].rem--;
            time++;

            if (v[idx].rem == 0)
            {
                v[idx].ct = time;
                v[idx].tat = v[idx].ct - v[idx].at;
                v[idx].wt = v[idx].tat - v[idx].bt;
                complete[idx] = true;
                cnt++;
            }
        }
        else
        {
            time++;
        }
    }

    cout << "P.Id. \t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T\n";

    for (int i = 0; i < n; i++)
    {
        cout << v[i].id << "\t" << v[i].at << "\t" << v[i].bt << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << "\t" << v[i].rt << endl;
    }

    return 0;
}
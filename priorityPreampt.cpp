// C++ implementation for priority with preamption.
// April 27 2025.
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int at, bt, ct, tat, wt, rt, id, pri, rem;
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
        // forgot to initialize rem, thanks to chatGpt, I found the error.
        v[i].rem = v[i].bt;
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
            if (!complete[i] && time >= v[i].at)
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
            // cout << "yo";
        }
        else
        {
            if (v[idx].rem == v[idx].bt)
            {
                v[idx].rt = time - v[idx].at;
            }

            v[idx].rem--;
            time++;
            
            if (v[idx].rem == 0)
            {
                complete[idx] = true;
                cnt++;
                v[idx].ct = time;
                v[idx].tat = v[idx].ct - v[idx].at;
                v[idx].wt = v[idx].tat - v[idx].bt;
            }
        }
    }
    cout << "P.Id. \t A.T\t B.T\tPri.\t C.T\t T.A.T\t W.T\t R.T\n";

    for (int i = 0; i < n; i++)
    {
        cout << v[i].id << "\t" << v[i].at << "\t" << v[i].bt << "\t"<< v[i].pri << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << "\t" << v[i].rt << endl;
    }

    return 0;
}
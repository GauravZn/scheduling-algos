// The code to implement first come first serve (fcfs) in C++.
// April 27 2025

#include <bits/stdc++.h>
using namespace std;

struct process
{
    int at, bt, ct, tat, wt, rt, id;
};

bool cmp(process &a, process &b)
{
    if (a.at < b.at)
    {
        return true;
    }
    if (a.at == b.at)
    {
        return a.id < b.id;
    }
    return false;
}

int main()
{
    int n;
    cout << "enter the number of processes:\n";
    cin >> n;

    vector<process> v(n);

    for (int i = 0; i < n; i++)
    {
        cout << "enter id:\n";
        cin >> v[i].id;
        cout << "enter at:\n";
        cin >> v[i].at;
        cout << "enter bt:\n";
        cin >> v[i].bt;
    }

    sort(v.begin(), v.end(), cmp);

    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].at > time)
        {
            time = v[i].at;
        }
        v[i].rt = time - v[i].at;
        time += v[i].bt;
        v[i].ct = time;
        v[i].tat = v[i].ct - v[i].at;
        v[i].wt = v[i].tat - v[i].bt;
    }

    cout << "P.Id. \t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T\n";

    for (int i = 0; i < n; i++)
    {
        cout << v[i].id << "\t" << v[i].at << "\t" << v[i].bt << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << "\t" << v[i].rt << endl;
    }

    return 0;
}
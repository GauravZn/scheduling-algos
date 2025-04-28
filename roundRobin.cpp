//  C++ implementation for the Round Robin algorithm.
//  April 27 2025
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int at, bt, ct, tat, wt, rt, id, rem;
};
bool cmp(process a, process b)
{
    if (a.at < b.at)
    {
        return true;
    }
    else if (a.at == b.at)
    {
        return a.id < b.id;
    }
    return false;
}
int main()
{
    int n, tq;
    cout << "enter the number of processes:\n";
    cin >> n;
    cout << "enter the time quanta:\n";
    cin >> tq;
    vector<process> v(n);

    for (int i = 0; i < n; i++)
    {
        cout << "enter id: at and bt\n";
        cin >> v[i].id >> v[i].at >> v[i].bt;
        v[i].rem = v[i].bt;
    }

    sort(v.begin(), v.end(), cmp);

    int time = v[0].at;

    queue<int> q;
    int cnt = 0;

    q.push(0);
    vector<int> Q(n,false);
    Q[0] = true;

    while (cnt < n)
    {

        while (!q.empty())
        {
            int fr = q.front();
            q.pop();

            if (v[fr].rem == v[fr].bt)
            {
                v[fr].rt = time - v[fr].at;
            }
            
            time += min(v[fr].rem, tq);
            v[fr].rem -= min(v[fr].rem, tq);

            for (int i = 0; i < n; i++)
            {
                if (time >= v[i].at && !Q[i])
                {
                    q.push(i);
                    Q[i] = true;
                }
            }

            if (v[fr].rem == 0)
            {
                cnt++;
                v[fr].ct = time;
                v[fr].tat = v[fr].ct - v[fr].at;
                v[fr].wt = v[fr].tat - v[fr].bt;
            }
            else
            {
                q.push(fr);
            }
        }
        time++;
    }

    cout << "P.Id. \t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T\n";

    for (int i = 0; i < n; i++)
    {
        cout << v[i].id << "\t" << v[i].at << "\t" << v[i].bt << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << "\t" << v[i].rt << endl;
    }

    return 0;
}
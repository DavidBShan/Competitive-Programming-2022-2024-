#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<string> dq;
    int T, M;
    cin >> T >> M;
    for (int i = 0; i < T; i++)
    {
        string X, C;
        cin >> X >> C;
        if (C == "in")
        {
            dq.push_back(X);
        }
        else
        {
            if (!dq.empty() && dq.back() == X)
            {
                dq.pop_back();
            }
            else if (!dq.empty() && dq.front() == X && dq.size())
            {
                dq.pop_front();
            }
        }
    }
    while (!dq.empty())
    {
        cout << dq.front() << endl;
        dq.pop_front();
    }
}
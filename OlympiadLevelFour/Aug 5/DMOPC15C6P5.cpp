    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        deque<long long> minDQ, maxDQ;
        long long N, K;
        long long ans = 0;
        cin >> N >> K;
        long long arr[N + 3];
        for (long long i = 0; i < N; i++) cin >> arr[i];
        for (long long i = 0, j = 0, temp; j < N; j++)
        {
            temp = arr[j];
            while (!minDQ.empty() && arr[minDQ.back()] > temp)
            {
                minDQ.pop_back();
            }
            while (!maxDQ.empty() && arr[maxDQ.back()] < temp)
            {
                maxDQ.pop_back();
            }
            minDQ.push_back(j);
            maxDQ.push_back(j);
            while (!maxDQ.empty() && !minDQ.empty() && arr[maxDQ.front()] - arr[minDQ.front()] > K)
            {
                if (arr[maxDQ.front()] == arr[i])
                {
                    maxDQ.pop_front();
                }
                if (arr[minDQ.front()] == arr[i])
                {
                    minDQ.pop_front();
                }
                i++;
            }
            ans += j - i + 1;
        }
        cout << ans << endl;
    }
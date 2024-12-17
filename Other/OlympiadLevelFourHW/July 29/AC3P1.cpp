    #include <bits/stdc++.h>
    using namespace std;
    int N, K;
    int main()
    {
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> N >> K;
        int arr[N + 1];
        unordered_map<int, int> mp;
        long long ans = 0;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int l = 0, r = 0; r < N; r++)
        {
            mp[arr[r]]++;
            while (mp.size() >= K)
            {
                ans += N - r;
                mp[arr[l]]--;
                if (!mp[arr[l]])
                    mp.erase(arr[l]);
                l++;
            }
        }
        cout << ans << endl;
    }
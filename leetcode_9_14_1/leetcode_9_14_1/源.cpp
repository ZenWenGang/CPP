#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<long long> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];

    int l = 0, r = 0;
    while (m--)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

}
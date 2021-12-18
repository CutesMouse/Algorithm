#include<iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
ll h[1000000];
int N,K,P;
ll m_v = -1;
int main()
{
    cin >> N >> K >> P;
    for (int i = 0; i < N; i++) cin >> h[i];
    sort(h,h+N);
    ll m_v1 = -1;
    if (K == 2) {
        ll ans = min(h[1] - h[0],h[N-1]-h[N-2]);
        cout << ans << endl;
        return 0;
    }
    int ed = K;
    for (; st < N-2; st++) {

    }
    for (int i = 0; i < K-2; i++) {
        ll dif = max(h[i+2] - h[i],h[i+1]-h[i]);
        if (m_v1 == -1) m_v1 = dif;
        m_v1 = max(m_v1,dif);
    }
    ll m_v2 = -1;
    // min n-k elements remove
    for (int i = N-K; i < N-2; i++) {
        ll dif = max(h[i+2] - h[i],h[i+1]-h[i]);
        if (m_v2 == -1) m_v2 = dif;
        m_v2 = max(m_v2,dif);
    }
    cout << min(m_v1,m_v2) << endl;
}

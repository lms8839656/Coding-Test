#include <iostream>

using namespace std;

long long int K, P, N, i;

int main(void)
{
    cin >> K >> P >> N;
    
    for(i = 1; i <= N; i++){
        K = K * P;
    }
    
    cout << K % 1000000007;
    
    return 0;
}

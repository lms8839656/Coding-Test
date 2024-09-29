#include <iostream>

using namespace std;

long long int K, P, N;

int main(void)
{
    cin >> K >> P >> N;
    
    long long int sum = K;
    
    for(long long int i = 1; i <= N*10; i++){
        sum = sum*P;
    }
    
    cout << sum % 1000000007;
    
    return 0;
}

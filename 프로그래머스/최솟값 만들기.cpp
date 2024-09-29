#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
    int answer = 0;
    int n = 5;
    vector<int> v(100000);
    
    v[0] = 0;
    v[1] = 1;
    
    for(int i = 2; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }
    
    answer = v[n] % 1234567;
    
    cout << answer;
    
    return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    int N;
        
    cin >> N;
    
    if(N < 1 || N > 100) return 0;

    
    for(int i = 0 + 1; i < N + 1; i++){
        
        for (int cnt = i; cnt > 0; cnt--){
            cout << "*"; 
        }
        if(i != N) cout << "\n";
    }
    
    return 0;
}

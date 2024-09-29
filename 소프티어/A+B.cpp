#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void Input();

int A, B, T;


int main(void)
{
    cin >> T;
    
    vector<int> A;
    vector<int> B;
    
    int a;
    int b;
    
    for(int i = 0; i < T; i++){
        cin >> a >> b; 
        A.push_back(a);
        B.push_back(b);
    }
    
    
    for(int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << A[i] + B[i] << "\n";
    }
    
    return 0;
}



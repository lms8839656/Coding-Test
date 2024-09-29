#include <iostream>
#include <algorithm>

#define MAX 1000

using namespace std;

int N;

int MAP[MAX];

void Input();

int main(void)
{
    Input();
    sort(MAP, MAP+N);
    
    for(int i = 0; i < N; i++){
        cout << MAP[i] << "\n";
    }
    
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> MAP[i];
    }
}

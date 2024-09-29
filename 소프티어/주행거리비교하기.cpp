#include <stdio.h>
#include <iostream>

using namespace std;

int A, B;

void Input();
void solution();

int main(void)
{
    Input();
    solution();
    
    return 0;
}

void Input(){
    cin >> A >> B;
}

void solution(){
    if(A>B){
        cout << "A";
    }
    else if(A<B){
        cout << "B";
    }
    else cout << "same";
}

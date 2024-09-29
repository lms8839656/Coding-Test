#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

int M, N, K;

int pass[MAX];
int button[MAX];
bool IsSecret = false;

void Input();
void Check();
void Output();

int main(void)
{
    Input();
    
    Check();
    Output();
    
    return 0;
}

void Input(){
    cin >> M >> N >> K;
    for(int i = 0; i < M; i++){
        cin >> pass[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> button[i];
    }
}

void Check(){
    for(int i = 0; i < N; i++){
        //cout << i << " ";
        if(button[i] == pass[0]){
            for(int j = 0; j < M; j++){
                if(button[i+j] != pass[j]) break;
                //cout << button[i+j] << " " << pass[j] << " ";
                if(j == M-1) IsSecret = true;
            }
        }
    }
}

void Output(){
    if(IsSecret == true) cout << "secret";
    else cout << "normal";
}

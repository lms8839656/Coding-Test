#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 500000

using namespace std;

int N, M;

int Ncard[MAX];
int Mcard[MAX];
int visited[MAX];

void Input();
void Search();

void DebugOutput();

int main(void)
{
    Input();

    Search();

    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Ncard[i];
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> Mcard[i];
    }
}

void Search(){
    sort(Ncard, Ncard+N);
    //sort(Mcard, Mcard+M);
    //DebugOutput();
    bool Flag = false;
    int sel = 0;
    for(int i = 0; i < M; i++){
        Flag = false;
        for(int j = 0; j < N; j++){
            
            if(Ncard[j] > Mcard[i]){
                //sel++;
                //break;
            }
            else if(Ncard[j] < Mcard[i]){
                //continue;
            }
            else if(Ncard[j] == Mcard[i]){
                Flag = true;
                //sel++;
                break;
            }
        }
        if(Flag == true) cout << "1 ";
        else cout << "0 ";
    }
    
}

void DebugOutput(){
    cout << "\n";
    
    for(int i = 0; i < N; i++){
        cout << Ncard[i] << " ";
    }
    
    cout << "\n";
}

#include <iostream>
#include <string>

#define MAX 100

using namespace std;

typedef struct _Gear{
    int state[8];
}Gear;

typedef struct _Oder{
    int GearNum;
    int Dest;
}Oder;

Gear myGear[4];
Oder myOder[MAX];
bool CheckGear[3];
bool visited[4];
int dx[2] = {-1, 1};

int K;

int sum = 0;

void Input();
void RotateClock(int x);
void RotateCount(int x);
void RunOder();
void IsCheckRotate(int x, int dest);
void ResetVisited();
void IsCheckGear();
void CalScore();

void DebugOutput();

int main(void)
{
    Input();
    RunOder();
    CalScore();
    //DebugOutput();
    return 0;
}

void Input(){
    string s;
    
    for(int i = 0; i < 4; i++){
        cin >> s;
        for(int j = 0; j < 8; j++){
            myGear[i].state[j] = s[j] - '0';
        }
    }
    
    cin >> K;
    
    for(int i = 0; i < K; i++){
        cin >> myOder[i].GearNum >> myOder[i].Dest;
    }
}

void RotateClock(int x){
    Gear tempGear = myGear[x];
    
    myGear[x].state[0] = tempGear.state[7];
    for(int i = 1; i < 8; i++){
        myGear[x].state[i] = tempGear.state[i-1];
    }
}

void RotateCount(int x){
    Gear tempGear = myGear[x];
    
    myGear[x].state[7] = tempGear.state[0];
    for(int i = 0; i < 7; i++){
        myGear[x].state[i] = tempGear.state[i+1];
    }
}

void RunOder(){
    int sel;
    for(int i = 0; i < K; i++){
        IsCheckGear();
        IsCheckRotate(myOder[i].GearNum-1, myOder[i].Dest);
        ResetVisited();
    }
}

void IsCheckRotate(int x, int dest){
    visited[x] = true;
    if(dest == 1){
        RotateClock(x);
    }
    else{
        RotateCount(x);
    }

    int nx;
    
    for(int i = 0; i < 2; i++){
        nx = x + dx[i];
        if(nx >= 4 || nx < 0 || visited[nx]) continue;
        if(i == 0 && CheckGear[x-1] == false) continue;
        if(i == 1 && CheckGear[x] == false) continue;
        
        IsCheckRotate(nx, dest*(-1));
    }
    
}

void ResetVisited(){
    for(int i = 0; i < 4; i++){
        visited[i] = false;
    }
}

void IsCheckGear(){
    for(int i = 0; i < 3; i++){
        if(myGear[i].state[3-1] == myGear[i+1].state[7-1]) CheckGear[i] = false;
        else CheckGear[i] = true;
    }
}

void CalScore(){
    if(myGear[0].state[0] == 1) sum = sum + 1;
    if(myGear[1].state[0] == 1) sum = sum + 2;
    if(myGear[2].state[0] == 1) sum = sum + 4;
    if(myGear[3].state[0] == 1) sum = sum + 8;
    cout << sum;
}

void DebugOutput(){
    cout << "\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            cout << myGear[i].state[j];
        }
        cout << "\n";
    }
}

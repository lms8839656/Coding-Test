#include <iostream> 
#include <stdio.h>

#define MAX 50
#define NOWPOS MAP[myRobot.r][myRobot.c]

using namespace std;

int MAP[MAX][MAX];

int N, M, num_clean;
bool IsPossibleClean = false;
bool IsPossibleGoFront = false;
bool IsRunning = true;

typedef struct _Robot{
    int r;
    int c;
    int head;
}Robot;

Robot myRobot;

void Input();
void Output();
void Move();
void Turn();
void Clean();
void SearchRoom();
void Run();
void CheckFront();
void GoBack();

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    Input();
    Run();
    Output();
    return 0;
}

void Input(){
    cin >> N >> M >> myRobot.r >> myRobot.c >> myRobot.head;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
}

void Output(){
    cout << num_clean;
}

void Move(){
    switch(myRobot.head){
        case 0:
            myRobot.r = myRobot.r - 1;
            break;
        case 1:
            myRobot.c = myRobot.c + 1;
            break;
        case 2:
            myRobot.r = myRobot.r + 1;
            break;
        case 3:
            myRobot.c = myRobot.c - 1;
            break;
    }
}

void Turn(){
    if(myRobot.head == 0) myRobot.head = 3;
    else myRobot.head--;
}

void Clean(){
    if(MAP[myRobot.r][myRobot.c] == 0){
        MAP[myRobot.r][myRobot.c] = 2;
        num_clean++;
    }
}

void SearchRoom(){
    int nx;
    int ny;
    
    for(int k = 0; k < 4; k++){
        nx = dx[k];
        ny = dy[k];
        if(MAP[myRobot.r + nx][myRobot.c + ny] == 0) {
            IsPossibleClean = true;
            break;
        }
        else IsPossibleClean = false;
    }
}

void Run(){
    while(1){
        Clean();
        SearchRoom();
        if(IsPossibleClean == true){
            while(1){
                Turn();
                CheckFront();
                if(IsPossibleGoFront == true){
                    IsPossibleGoFront = false;
                    Move();
                    break;
                }
            }
            
        }
        else{
            GoBack();   
        }
        
        if(IsRunning == false) break;
    }
}

void CheckFront(){
    switch(myRobot.head){
        case 0:
            if(MAP[myRobot.r - 1][myRobot.c] == 0)
                IsPossibleGoFront = true;
            break;
        case 1:
            if(MAP[myRobot.r][myRobot.c + 1] == 0)
                IsPossibleGoFront = true;
            break;
        case 2:
            if(MAP[myRobot.r + 1][myRobot.c] == 0)
                IsPossibleGoFront = true;
            break;
        case 3:
            if(MAP[myRobot.r][myRobot.c - 1] == 0)
                IsPossibleGoFront = true;
            break;
    }
}

void GoBack(){
        switch(myRobot.head){
        case 0:
            if(MAP[myRobot.r + 1][myRobot.c] == NULL || MAP[myRobot.r + 1][myRobot.c] == 1) {
                IsRunning = false;
                return;
            }
            myRobot.r = myRobot.r + 1;
            break;
        case 1:
            if(MAP[myRobot.r][myRobot.c - 1] == NULL || MAP[myRobot.r][myRobot.c - 1] == 1) {
                IsRunning = false;
                return;
            }
            myRobot.c = myRobot.c - 1;
            break;
        case 2:
            if(MAP[myRobot.r - 1][myRobot.c] == NULL || MAP[myRobot.r - 1][myRobot.c] == 1) {
                IsRunning = false;
                return;
            }
            myRobot.r = myRobot.r - 1;
            break;
        case 3:
            if(MAP[myRobot.r][myRobot.c + 1] == NULL || MAP[myRobot.r][myRobot.c + 1] == 1) {
                IsRunning = false;
                return;
            }
            myRobot.c = myRobot.c + 1;
            break;
    }
}

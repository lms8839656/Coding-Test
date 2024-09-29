#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAPSIZE 4

using namespace std;

int MAP[MAPSIZE][MAPSIZE];
bool visited[MAPSIZE][MAPSIZE];
int depth[MAPSIZE][MAPSIZE];


int dx[8] = {0,1,1,1,0,-1,-1,-1}
int dy[8] = {-1,-1,0,1,1,1,0,-1}

int max = 0;

typedef struct _Fish{
    int Head;
    int x;
    int y;
    int num;
}Fish;

typedef struct _Shark{
    int Head;
    int x;
    int y;
};

void Input();
void EnterShark();
void MoveFish();
void TurnFish();
void IsPossibleMove();
void MoveShark();
void DFS();


int main(void)
{
    
    return 0;
}

void Input(){
    
}

void EnterShark(){
    shark.pos = 0,0;
    shark.head = fish[0,0].head;
}

void MoveFish(){
    for(int i = 0; i < 16; i++){
        while(!IsPossibleMove){
            TurnFish();
        }
        Fish[i] = Fish.dx.dy;
    }
    
}

void TurnFish(){
    dx, dy++ ->CountClockTurn
    if dx,dy == 8 -> 0;
}

void IsPossibleMove(){
    if(PossibleMove)
    else return false
}

void MoveShark(){
    Shark.Head = Fish.Head;
    
}

void DFS(){
    
}

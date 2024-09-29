#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define CURVMAX 20

using namespace std;

typedef struct _Curv{
    int x;
    int y;
    int d;
    int g;
}Curv;

Curv myCurv[CURVMAX];

int MAP[MAX][MAX];
int tempMAP[MAX][MAX];
int curvMAP[MAX][MAX];


int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void Input();
void FindMaxPoint();
void DragonCurv();


int main(void)
{
    
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> myCurv[i].x >> myCurv[i].y >> myCurv[i].d >> myCurv[i].g;
    }
}

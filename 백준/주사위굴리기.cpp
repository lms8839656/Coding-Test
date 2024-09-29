#include <iostream> 
#include <stdio.h>

#define MAX 20
#define NOWPOS MAP[myDice.r][myDice.c]

using namespace std;

int MAP[MAX][MAX];
int N, M, k;
typedef struct _Dice {
    int c;
    int r;
    int top;
    int bottom;
    int left;
    int right;
    int front;
    int back;
}Dice;

Dice myDice{ 0,0,0,0,
            0,0,0,0 };

int order[1000];

void Input();
void Start();
void Move(int num);
void Swap();
void Output();

int main(void)
{
    Input();


    Start();

    return 0;
}

void Start() {
    for (int i = 0; i < 1000; i++) {
        if (order[i] == NULL) break;
        Move(order[i]);


    }
}

void Input() {
    cin >> N >> M >> myDice.r >> myDice.c >> k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> order[i];
    }
}

void Move(int num) {
    int temp;
    switch (num) {
    case 1:
        if (myDice.c+1 >= M) return;
        temp = myDice.bottom;
        myDice.bottom = myDice.right;
        myDice.right = myDice.top;
        myDice.top = myDice.left;
        myDice.left = temp;
        myDice.c++;
        Swap();
        Output();
        break;
    case 2:
        if (myDice.c-1 < 0) return;
        temp = myDice.bottom;
        myDice.bottom = myDice.left;
        myDice.left = myDice.top;
        myDice.top = myDice.right;
        myDice.right = temp;
        myDice.c--;
        Swap();
        Output();
        break;
    case 3:
        if (myDice.r-1 < 0) return;
        temp = myDice.bottom;
        myDice.bottom = myDice.front;
        myDice.front = myDice.top;
        myDice.top = myDice.back;
        myDice.back = temp;
        myDice.r--;
        Swap();
        Output();
        break;
    case 4:
        if (myDice.r+1 >= N) return;
        temp = myDice.bottom;
        myDice.bottom = myDice.back;
        myDice.back = myDice.top;
        myDice.top = myDice.front;
        myDice.front = temp;
        myDice.r++;
        Swap();
        Output();
        break;
    }
}

void Output() {
    cout << myDice.top << "\n";
}

void Swap() {
    if (NOWPOS == 0) {
        NOWPOS = myDice.bottom;
    }
    else {
        myDice.bottom = NOWPOS;
        NOWPOS = 0;
    }
}

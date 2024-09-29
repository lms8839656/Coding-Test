#include <iostream> 
#include <stdio.h>

#define MAX 1000000

using namespace std;

int N, K, S, A, B;

int score[MAX+1];

double num[10000+1];

void Input();
void solution();
void Output();
void DebugOutput();

int main(void)
{
    Input();
    //DebugOutput();
    solution();
    Output();
    return 0;
}

void Input(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> score[i];
    }
}

void solution(){
    double sum = 0;
    for(int m = 0; m < K; m++){
        cin >> A >> B;
        for(int i = A; i <= B; i++){
            sum = score[i] + sum;
        }
        num[m] = sum / double(B - A + 1) + num[m];
        sum = 0;
    }
}

void Output(){
    for(int i = 0; i < K; i++){
        printf("%.2f\n", num[i]); 
    }
}

void DebugOutput(){
    for(int i = 1; i <= N; i++){
        cout << score[i] << " ";
    }
}

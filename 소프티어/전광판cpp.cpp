#include <iostream>
#include <vector>

#define MAX 1000

using namespace std;



typedef struct _Case{
    int num;
    int seg[5][7];
}Case;

Case myCase[MAX];

int N;

void Input();
void DebugOutput();
void SetSeg();
void CalSeg();

int main(void)
{
    Input();
    DebugOutput();
    
    return 0;
}

void Input(){
    cin >> N; 

    for(int i = 0; i < N*2; i++){
        cin >> myCase[i].num;
    }
}

void DebugOutput(){
    for(int i = 0; i < N*2; i++){
        cout << myCase[i].num << "\n";
    }
}

void SetSeg(){
    //�ڶ�� ���ϰ� ���ڵ��� ���� ���ϱ� 
}

void CalSeg(){
    //2�� ���� ���� 
}

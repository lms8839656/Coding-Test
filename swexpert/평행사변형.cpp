#include<iostream>

#define MAX 100

using namespace std;

void Input();
void Output();

int TC;
int N[MAX];

int Sol[MAX];

int main(int argc, char** argv)
{
    Input();
    Output(); 
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void Input(){
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> N[i];
        Sol[i] = N[i] * N[i];
    }
}



void Output(){
    for(int i = 0; i < TC; i++){
        cout << "#" << i+1 << " " << Sol[i] << "\n";
    }
}

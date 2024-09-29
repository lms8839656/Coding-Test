#include <iostream>
#include <stdio.h>


using namespace std;

#define MAX 1000000

int N, B, C;

int A[MAX] = {NULL};

long long int answer = 0;

void Input();
void CalSub();


int main(void)
{
    
    Input();
    
    
    //printf("%d", ((A[2]-B)/(C*1)));
    
    CalSub();
    answer = answer + N;
    cout << answer;
    
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cin >> B >> C;    
}

void CalSub(){
    for(int i = 0; i < N; i++){
        if(A[i] == NULL) break;
        if(A[i]-B != 0){
            for(int j = 1; j < A[i]; j++){       
                if((float(A[i]-B)/float(C*j)) <= 1.0){
                    answer = answer + j;
                    break;
                }
            }
        }
    }
}

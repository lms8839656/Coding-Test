#include <iostream>

#define MAX 200

using namespace std;

int MAP[2*MAX+1];
int N, K;

void Input();
void Rotate();
void MoveRobot();
void SetRobot();
void CalZeroSpace();
void CheckDown();
void DebugOutput();


typedef struct _Belt{
	bool IsRobot;
	int Du;
}Belt;

Belt myBelt[2*MAX+1];
Belt tempBelt[2*MAX+1];

bool IsEndRun = false;
int zeroSapce = 0;
int DuCount = 0;


int main(void)
{
	Input();
	
	while(zeroSapce < K){
	    DuCount++;
	    Rotate();
	    CheckDown();
	    MoveRobot();
	    CheckDown();
	    SetRobot();
	    CalZeroSpace();
    }
	
	
	
	
    cout << DuCount;
	return 0;
}

void Input(){
	cin >> N >> K;
	for(int i = 1; i <= 2*N; i++){
		cin >> myBelt[i].Du;
	}
}

void Rotate(){
	for(int i = 1; i <= 2*N; i++){
		if(i == 2*N){
			tempBelt[1] = myBelt[i];
			continue;
		}
		tempBelt[i+1] = myBelt[i];
	}
	
	for(int i = 1; i <= 2*N; i++){
		myBelt[i] = tempBelt[i];
	}
}

void MoveRobot(){
	for(int i = N-1; i >= 1; i--){
		if(!myBelt[i+1].IsRobot && myBelt[i+1].Du > 0 && myBelt[i].IsRobot){
			myBelt[i+1].IsRobot = true;
			myBelt[i+1].Du--;
			myBelt[i].IsRobot = false;
		}
	}
	
}

void SetRobot(){
	if(myBelt[1].Du != 0){
	    myBelt[1].IsRobot = true;
	    myBelt[1].Du--;
    }
}

void CalZeroSpace(){
    zeroSapce= 0;
	for(int i = 1; i <= 2*N; i++){
	    if(myBelt[i].Du == 0) zeroSapce++;
    }
}

void CheckDown(){
    myBelt[N].IsRobot = false;
}


void DebugOutput(){
	for(int i = 1; i <= N; i++){
		cout << myBelt[i].Du << " ";
	}
	cout << "\n";
	for(int i = 2*N; i > N; i--){
		cout << myBelt[i].Du << " ";
	}
	cout << "\n";
	cout << "\n";

}

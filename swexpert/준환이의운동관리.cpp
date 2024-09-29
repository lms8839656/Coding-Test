#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> L, U, X;

void Input();
void Output();

int main(void)
{
    Input();
    Output();
    
    return 0;
}

void Input(){
    cin >> T;
    int tempL, tempU, tempX;
    for(int i = 0; i < T; i++){
        cin >> tempL >> tempU >> tempX;
        L.push_back(tempL);
        U.push_back(tempU);
        X.push_back(tempX);
    }
}

void Output(){
    for(int i = 0; i < T; i++){
        cout << "#" << i+1 << " ";
        if(X[i] < L[i]){
            cout << L[i]-X[i];
        }
        else if(X[i] > U[i]){
            cout << "-1";
        }
        else{
            cout << "0";
        }
        cout << "\n";
    }
}

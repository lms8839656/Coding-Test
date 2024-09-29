#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> N;

void Input();

int main(void)
{
    Input();
    
    return 0;
}

void Input(){
    cin >> T;
    int tempN;
    for(int i = 0; i < T; i++){
        cin >> tempN;
        N.push_back(tempN);
    }
    
    for(int i = 0; i < T; i++){
        cout << "#" << i+1 << " " <<N[i] / 3 << "\n";
    }
}

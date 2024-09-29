#include <iostream>

#define MAX 10000+1

using namespace std;

void init(int N);
void add(int id, int F, int ids[]);
void del(int id1, int id2);
void recommend(int id, int list[]);



int main(void)
{
	
	return 0;
}

void init(int N){
	cin >> n_User;
}

void add(int id, int F, int ids[]){
	for(int i = 0; i < F; i++){
		myUser[id].ids[i] = true;
		myUser[i].ids[id] = true;
	}
}

void del(int id1, int id2){
	myUser[id1].ids[id2] = false;
	myUser[id2].ids[id1] = false;
}

void recommend(int id, int list[]){
	
}

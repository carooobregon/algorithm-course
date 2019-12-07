#include <iostream>
#include <queue>

using namespace std;

#define N 5

int mayoresimo (int datos[N], int k){

	priority_queue<int> pq;
	for(int i = 0; i < N; i++){
		pq.push(datos[i]);
	}

	for(int i = 0; i < k-1; i++){
		pq.pop();
	}
	return pq.top();
}

int main(){

	int datos[N] = {3,9,1,2,4};

	cout << mayoresimo(datos,2) << endl;

}
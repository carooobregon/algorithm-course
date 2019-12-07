/*
	Carolina Obregon B.
	Analisis y Diseño de Algoritmos
	A01251983
*/

#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

int binarySearch(int lowerBound, int upperBound, int target, vector<int> input, int &counter){
	if(lowerBound > upperBound)
		return 0;
	else {
		counter++;
		int mid = (lowerBound + upperBound) / 2;
		if( target == input[mid])
			return mid;
		else if (target>input[mid])
			return(binarySearch(lowerBound, mid-1, target, input, counter));
		else 
			return(binarySearch(mid+1,upperBound, target, input, counter));
	}
}

int main(){

  	ifstream myFile;
  	myFile.open("matriculas.txt");

  	vector<int> matriculas;
  	int minM, maxM;
  	int minMindex, maxMindex, answer;
  	int counter = 0;
  	bool repeat = true;
  	char inputR;

  	while (!myFile.eof()) {
  		int inputMat;
  		myFile >> inputMat;
  		matriculas.push_back(inputMat);
 	}
 	while(repeat) {
 	 	cout << "Desde que matricula quieres buscar?" << endl;
 	 	cin >> minM;
 	 	cout << "Hasta que matricula quieres buscar?" << endl;
 	 	cin >> maxM;
 	
 	 	minMindex = binarySearch(0, matriculas.size()-1,minM, matriculas, counter);
 	 	maxMindex = binarySearch(0, matriculas.size()-1, maxM, matriculas, counter);
 	 	answer = minMindex - maxMindex + 1;
 	 	cout << "Hay " << answer << "matriculas en ese rango" << endl;
 	 	cout << "Se hicieron " << counter << "comparaciones" << endl;
 	 	cout << "Quiere revisar otro rango? S/N" << endl;
 	 	cin >> inputR;
 	 	if(inputR == 'S')
 	 		repeat = true;
 	 	else
 	 		repeat = false;
 	 }
}
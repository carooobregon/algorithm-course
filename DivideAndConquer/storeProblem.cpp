// Un arreglo contiene la secuencia de números enteros que corresponde a
// los datos de las ventas que tuvo cierto negocio en los 365 días del año.
// Se sabe de antemano que el negocio tenía una tendencia a ir incrementando
// día a día sus ventas desde el primer día del año hasta que ocurrió un incidente
// que lo afectó y susventas se cayeron, mostrando un decremento día con día hasta terminar el año

#include <iostream>
#include <vector>

using namespace std;

int helperPeak(vector<int> earnings, int low, int high, int &comparaciones){
	// find middle element
	int n = earnings.size();
	int mid = low + (high - low)/2;  /* (low + high)/2 */
	comparaciones++;
	if((mid == 0 || (earnings[mid] >= earnings[mid+1])) && (mid == n-1 || earnings[mid] >= earnings[mid-1]))
		return mid;
	if(mid > 0 && earnings[mid-1] > earnings[mid])
		return helperPeak(earnings, low, mid-1, comparaciones);
	else
		return helperPeak(earnings, mid+1, high, comparaciones);
}

int findPeak(vector<int> earnings, int &comparaciones){
	return helperPeak(earnings, 0, earnings.size()-1, comparaciones);
}

int main(){
	vector<int> ganancias {1,2,3,5,6,7,8,9,10,12,16,6,3,1};
	int comparaciones = 0; 
	for(int i = 0; i < ganancias.size(); i++)
		cout <<ganancias[i] << " ";
	cout << endl;
	cout << "El dia que empezaron a bajar las ventas fue " << findPeak(ganancias, comparaciones)+1 << endl;
	cout << "Comparaciones: " << comparaciones << endl;

}
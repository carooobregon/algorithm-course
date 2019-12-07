#include <iostream>

using namespace std;

int currentSum;
int *myNums; 

bool enoughLeft(int curr, int target){
	int res = 0;
	if(curr == target)
		return true;
	for(int i = curr; i <= target; i++){
		res += i;
	}
	if(res >= target)
		return true;
	else
		return false;
}

bool valido(int i, int currSum, int target) {
     int j = 1;
     bool answer = true;
    if (currentSum + i <= target && enoughLeft(i, target)) {
     	return true;
    }
     return false;
}5

void sumEqualsN(int i, int currSum, int target ) {
     if(valido(i, currSum, target)){ 
       if (currSum == target) {
       	int idx =1;
       	while (myNums[idx] == 0)
       		idx++;
       	cout << myNums[idx]; 
		for(int j=idx+1; j<=target; j++)
			if (myNums[j] != 0)
				cout << '+' << myNums[j];
			cout << endl;
       }
       else {
		 	myNums[i+1] = i+1;
		 	sumEqualsN(i+1, currSum+i+1, target); 
		 	myNums[i+1] = 0;
		 	sumEqualsN(i+1, currSum, target); 
       }
     }

     return;

}


int main(){
	int n;
	cout << "N ";
	cin >> n;
	myNums = new int[n+1];
	sumEqualsN(0, 0, n);
}
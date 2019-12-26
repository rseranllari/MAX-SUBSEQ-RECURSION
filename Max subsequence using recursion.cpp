#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


void populate(int * &array, int size)
{
    srand(0);
    array = new int[size];
    
    for(int i = 0; i < size ; i++)
    {
        //Generate values between -10 * size and 10 * size
        array[i] = rand() % (size * 20 + 1) - size * 10;
    }
}

void print(int * array, int size)
{
    for (int i = 0; i < size; i++)
        cout <<"Array[" << i << "] = " <<  array[i] << endl;
}

void sort (int * array, int size) {
	if (size == 1)
		return;
		
	int temp = 0; 	
	for (int i = 0; i < size; i++) {
		if (array[0] > array[i]) {
			temp = array[0];
			array[0] = array[i];  
			array[i] = temp; 
		}
	}

	sort(array + 1, size - 1); 
}

int binarySearch(int * array, int left, int right, int x) {
	int i = (left + right) / 2;
		
		if (left > right) {
			return -1; 
		}
		else if (x == array[i]) {
			return i;
		}
		else if (x > array[i]) {
			left = i + 1;
		}
		else {
			right = i - 1;
		}

		binarySearch(array, left, right, x); 
}

int sum (int *array, int left, int right) {
	int i = left, sum = 0;
	
	while ( i < right) {
		sum += array[i];
		i++;
	}
	
	return sum; 
}



int mss (int * array, int left, int right) {
	
	int maxSumLeft = 0, maxSumRight = 0; 
	int leftSum = 0, rightSum = 0;
	int center = (left + right) / 2;
	
	if (left == right) {
		return array[left];
	}
		
	int maxLeftSum = mss(array, left, center);
	int maxRightSum = mss(array, center + 1, right);
	
	for (int i = center; i >= left; i--) {
		leftSum += array[i];
			if (leftSum > maxSumLeft)
				maxSumLeft = leftSum;
	}
	
	for (int i = center + 1; i <= right; i++) {
		rightSum += array[i];
		if (rightSum > maxSumRight) 
			maxSumRight = rightSum;
	}
	
	return max(maxLeftSum, max(maxRightSum, maxSumLeft + maxSumRight));
}

int mss1(int * array, int left, int right) {
	
	int count = sum(array, left, right);
	
	return mss(array, left, right);
	
}

int linearSearch (int * array, int left, int right, int x) {
	
	int i = left;
	for (i; i < right; i++) {
		if (x == array[i]) {
			return i;
		}
	}
	return -1; 
}

int main () {
	int * array; 
	int size = 10000;
	populate (array, size); 
	
	int result; 
	clock_t start = 0, end = 0; 
	
//	print(array, size); 
	 
  	start  = clock();
    cout << binarySearch(array, 0, size - 1, -967459) <<endl;
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for algorithm 1 to obtain the result." << endl;
	
	cout << "THE max sequence is: " << mss1(array, 0, size - 1);
	
	start = 0;
	end = 0;
	start  = clock();
    cout << linearSearch(array, 0, size - 1, -967459) <<endl;
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for algorithm 1 to obtain the result." << endl;
	
	cout << "THE max sequence is: " << mss1(array, 0, size - 1);  
	
	start = 0;
	end = 0;
	start  = clock();
    cout << mss(array, 0, size - 1) <<endl;
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for algorithm 1 to obtain the result." << endl;
	
	cout << "THE max sequence is: " << mss1(array, 0, size - 1);
	
	
	
	
	return 0;
}

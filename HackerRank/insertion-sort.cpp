#include <iostream>
using namespace std;

long long int merge(int arr[], int temp[], int l, int m, int r) {  
    int i, j, k;  
    long long int count = 0;  
  
    i = l; 
    j = m;
    k = l;
    while (i<=m-1 && j<=r) {  
        if (arr[i] <= arr[j])  
            temp[k++] = arr[i++];   
        else {  
            temp[k++] = arr[j++];  
            count += m-i;  
        }  
    }  
  
    while (i<=m-1)  
        temp[k++] = arr[i++];  
  
    while (j<=r)  
        temp[k++] = arr[j++];  
  
    for (i=l;i<=r;i++)  
        arr[i] = temp[i];  
  
    return count; 
}
  
long long int _mergeSort(int arr[], int temp[], int l, int r) {  
    int m;
	long long int count = 0;  

    if (r>l) {  
        m = (r+l)/2;  
  
        count = _mergeSort(arr, temp, l, m);  
        count += _mergeSort(arr, temp, m+1, r);  
        count += merge(arr, temp, l, m+1, r);  
    }  
    
    return count;  
}

long long int mergeSort(int arr[], int n)  {  
    int temp[n];  
    return _mergeSort(arr, temp, 0, n-1);  
}

int main () {

	int t;
	cin >> t;
	
	while (t>0) {
		int n; 
		cin >> n;
		int v[n];

		for (int i=0;i<n;i++)
			cin >> v[i];

		cout << mergeSort(v,n) << endl;
		
		t--;
	}

	return 0;
}
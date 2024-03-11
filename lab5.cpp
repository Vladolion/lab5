#include <iostream>
#include <iomanip>
#include <vector>

void displayArray(std::vector<int> arr){
  for (int i = 0; i < arr.size(); i++){
    std::cout << std::setw(3) << arr[i];
  }
}
void displayArray(int* arr, int n){
  for (int i = 0; i < n; i++) {
    std::cout << std::setw(3) << arr[i];
  }
}

void vz1_2(){
  int n;
  std::cout<<"Number of elements in array: ";
  std::cin>>n;
  
  std::vector<int> arr;

  for (int i = 0; i < n; i++){
    arr.push_back(rand()%100);
  }

  std::cout << "Initial array" << std::endl;
  displayArray(arr);
  std::cout << std::endl;

  
  for (int i = 0; i < arr.size(); i++){
    if (arr[i] % 2 != 0){
      arr.erase(arr.begin() + i);
      i--;
    }
  }

  std::cout << "After removing odd numbers from array: " << std::endl;
  displayArray(arr);
  std::cout << std::endl;

  int k;
  std::cout << "Enter the amount of elemnts to add to the beginning  of the array: ";
  std::cin >> k;

  for (int i = 0; i < k; i++){
    arr.insert(arr.begin(), rand() % 100);
  }

  std::cout << "After adding elemnts to the beginning of the array: " << std::endl;
  displayArray(arr);
  std::cout << std::endl;
}

void z3_4(){
  const int n = 9;
  
  int arr[n];
  for(int i = 0; i<n;i++){
    arr[i] = rand()%100;
  }
  
  std::cout<<"Initial array: "<<std::endl;
  displayArray(arr, n);
  std::cout << std::endl;

  for (int i = 1; i < n; i+=2) {
    int t = arr[i-1];
    arr[i-1] = arr[i];
    arr[i] = t;
  }
  std::cout << "After switchig elements on odd and even indexes: "<<std::endl;
  displayArray(arr, n);
  std::cout<<std::endl;

  int m;
  std::cout << "Element to find: ";
  std::cin >> m;
  
  int mn = -1;
  for (int i = 0; i < n; i++) {
    if(arr[i]==m){
      mn=i;
      break;
    }
  }

  if(mn>=0){
    std::cout << "Element "<<m<<" found at "<<mn;
  }
  else{
    std::cout << "Element "<<m<<" not found";
  }
  std::cout << std::endl;

}

void z5(){
  const int n = 10;

  int arr[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = rand() % 100;
    }
  }

  std::cout << "Initial array" << std::endl;
  for(int i = 0; i<n; i++){
    displayArray(arr[i], n);
    std::cout<<std::endl;
  }
  std::cout<<std::endl;

  int sum = 0;
  std::cout<<"Selected elements:"<<std::endl;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n/2;j++){
      std::cout<<std::setw(3)<<"";
    }
    for(int j = 0; j < abs((n/2) - i) + (i<n/2 && n%2==0?0:1);j++){
      std::cout<<std::setw(3)<<arr[i][n/2+j];
      sum+=arr[i][n/2+j];
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
  std::cout<<"Sum of selected elements: "<< sum << std::endl;
}

void vz6(){
  int n = 10;

  vector<vector<int>> arr;
  
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++)
  }

}

void z6(){
  srand(2);
  int n = 10;

  int** arr = new int* [n];
  for (int i = 0; i<n; i++)
    arr[i] = new int[n];

  std::cout<<std::endl;
  std::cout<<"Initial array: "<<std::endl;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      arr[i][j] = rand() % 100;
    }
    displayArray(arr[i], n);
    std::cout<<std::endl;
  }

  std::cout<<std::endl;
  int maxCol = 0;
  int maxRow = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(arr[maxRow][maxCol]<arr[i][j]){
        maxRow = i;
        maxCol = j;
      }
    }
  }
  std::cout<<std::endl;
  std::cout<<maxRow<<", "<< maxCol;
  
  int** arr2 = new int*[n];
  for(int i = 0; i<n; i++)
    arr2[i] = new int[n+1];

  std::cout<<std::endl;
  std::cout<<"New array: "<<std::endl;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n+1; j++){
      arr2[i][j] = (j>=maxCol+1?(j!=maxCol+1?arr[i][j-1]:0):arr[i][j]);
      std::cout<<std::setw(3)<<arr2[i][j];
    }
    std::cout<<std::endl;
  }

  arr = arr2;

  std::cout<<std::endl;
  std::cout<<"Initial array after change"<<std::endl;
  for(int i = 0; i<n; i++){
    displayArray(arr[i], n+1);
    std::cout<<std::endl;
  }

  for(int i = 0; i<n;i++)
    delete[] arr2[i];
  delete[] arr2;

  for (int i = 0; i < n; i++)
    delete[] arr[i];
  delete[] arr;
}

int main (int argc, char *argv[]) {
  std::cout<<"Завдання 1-2"<<std::endl;
  vz1_2();

  std::cout<<std::endl;
  std::cout<<"Завдання 3-4"<<std::endl;
  z3_4();

  std::cout << std::endl;
  std::cout << "Завдання 5" << std::endl;
  z5();

  std::cout<<std::endl;
  std::cout<< "Завдання 6" << std::endl;
  z6();
  return 0;
}

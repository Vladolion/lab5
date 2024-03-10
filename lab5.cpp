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
void displayArray(int n, int* arr[]){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << std::setw(2) << arr[i][j];
    }
    std::cout << std::endl;
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
  const int n = 5;

  int arr[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = rand() % 10;
    }
  }

  std::cout << "Initial array" << std::endl;
  displayArray(int(n), arr);
}

int main (int argc, char *argv[]) {
  std::cout<<"Завдання 1-2"<<std::endl;
  //vz1_2();

  std::cout<<std::endl;
  std::cout<<"Завдання 3-4"<<std::endl;
  //z3_4();

  std::cout << std::endl;
  std::cout << "Завдання 5" << std::endl;
  z5();
  return 0;
}

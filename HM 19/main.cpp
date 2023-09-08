//
//  main.cpp
//  HM 19
//
//  Created by Дмитрий Сергеевич on 08.09.2023.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>



//task1
int lol(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return lol(b, a % b);
    }
}
//task2
int mirror_number(int num) {
    int mirror = 0;
    
    while (num > 0) {
        mirror = mirror * 10 + num % 10;
        num /= 10;
    }
    
    return mirror;
}

//task3
int findAndSort(int arr[], int length, int N) {
    int position = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] == N) {
            position = i;
            break;
        }
    }
    if (position == -1) {
        return -1;
    }
    std::sort(arr + position + 1, arr + length);
    
    return position;
}

//task4
void fillArray(int arr1[], int size1, int A, int B) {
    srand(time(NULL));
    for (int i = 0; i < size1; i++) {
        arr1[i] = rand() % (B - A + 1) + A;
    }
}


int main(int argc, const char * argv[]) {
//task1
    int num1, num2;
      std::cout << "Введите два числа: ";
      std::cin >> num1 >> num2;
      int result = lol(num1, num2);
      std::cout << "Наибольший общий делитель: " << result << std::endl;
    
    //task2
    int number;
       std::cout << "Enter a number: ";
       std::cin >> number;
       int mirroredNumber = mirror_number(number);
       std::cout << "Mirrored number: " << mirroredNumber << std::endl;
    
    //task3
    int arr[] = {1, 4, 3, 2, 5};
      int length = sizeof(arr) / sizeof(arr[0]);
      int N = 3;
      
      int position = findAndSort(arr, length, N);
      
      if (position == -1) {
          std::cout << "Число " << N << " не найдено в массиве" << std::endl;
      } else {
          std::cout << "Позиция числа " << N << " в массиве: " << position << std::endl;
          std::cout << "Отсортированный массив: ";
          for (int i = 0; i < length; i++) {
              std::cout << arr[i] << " ";
          }
          std::cout << std::endl;
      }
    
    //task4
    const int size1 = 10;
    int arr1[size1];

    int A = 1;
    int B = 10;

    fillArray(arr, length, A, B);

    // Вывод массива
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }



   
    return 0;
}

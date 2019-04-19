/*****************************************************************************
  Title          : main.cpp
  Author         : Keisuke Suzuki
  Created on     : November 28, 2018
  Description    : A main program for testing the class SortingTests with 
                 : varius kind of arrays which are randomly generated,
                 : accending, descending, last ten ramdom or few random
  Purpose        : To get running times of each kind of array for four sizes
  
******************************************************************************/
#include <iostream>
#include "SortingTests.hpp"

int main() {

    const size_t num1=100;
    const size_t num2=1000;
    const size_t num3=10000;
    const size_t num4=100000;

    int random_arr100[num1];
    int random_arr1000[num2];
    int random_arr10000[num3];
    int random_arr100000[num4];

    generateRandomArray(random_arr100, num1);
    generateRandomArray(random_arr1000, num2);
    generateRandomArray(random_arr10000, num3);
    generateRandomArray(random_arr100000, num4);

    int accending_arr100[num1];
    int accending_arr1000[num2];
    int accending_arr10000[num3];
    int accending_arr100000[num4];

    generateAscendingArray(accending_arr100, num1);
    generateAscendingArray(accending_arr1000, num2);
    generateAscendingArray(accending_arr10000, num3);
    generateAscendingArray(accending_arr100000, num4);

    int descending_arr100[num1];
    int descending_arr1000[num2];
    int descending_arr10000[num3];
    int descending_arr100000[num4];

    generateDescendingArray(descending_arr100,num1);
    generateDescendingArray(descending_arr1000,num2);
    generateDescendingArray(descending_arr10000,num3);
    generateDescendingArray(descending_arr100000,num4);

    int tenrandom_arr100[num1];
    int tenrandom_arr1000[num2];
    int tenrandom_arr10000[num3];
    int tenrandom_arr100000[num4];

    generateLastTenRandomArray(tenrandom_arr100,num1);
    generateLastTenRandomArray(tenrandom_arr1000,num2);
    generateLastTenRandomArray(tenrandom_arr10000,num3);
    generateLastTenRandomArray(tenrandom_arr100000,num4);

    int fewrandom_arr100[num1];
    int fewrandom_arr1000[num2];
    int fewrandom_arr10000[num3];
    int fewrandom_arr100000[num4];

    generateFewRandomArray(fewrandom_arr100,num1);
    generateFewRandomArray(fewrandom_arr1000,num2);
    generateFewRandomArray(fewrandom_arr10000,num3);
    generateFewRandomArray(fewrandom_arr100000,num4);

    std::cout<<std::endl;

    std::cout<<"Testing with random array\n";
    std::cout<<"Insertion Sort\n";
    for(int i=0; i<num2; i++)
        std::cout<<random_arr1000[i]<<" ";
    std::cout<<std::endl;

    std::cout<<sortTest(&insertionSort,random_arr100, num1)<<std::endl;
    std::cout<<sortTest(&insertionSort,random_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&insertionSort,random_arr10000, num3)<<std::endl;
    //std::cout<<sortTest(&insertionSort,random_arr100000, num4)<<std::endl;

    std::cout<<"Selection Sort\n";

    std::cout<<sortTest(&selectionSort,random_arr100, num1)<<std::endl;
    std::cout<<sortTest(&selectionSort,random_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&selectionSort,random_arr10000, num3)<<std::endl;
    //std::cout<<sortTest(&selectionSort,random_arr100000, num4)<<std::endl;

    std::cout<<"Merge Sort\n";

    std::cout<<mergeSortTest(random_arr100, num1)<<std::endl;
    std::cout<<mergeSortTest(random_arr1000, num2)<<std::endl;
    std::cout<<mergeSortTest(random_arr10000, num3)<<std::endl;
    std::cout<<mergeSortTest(random_arr100000, num4)<<std::endl;

    std::cout<<std::endl;

    std::cout<<"Testing with accending array\n";
    std::cout<<"Insertion Sort\n";

    std::cout<<sortTest(&insertionSort,accending_arr100, num1)<<std::endl;
    std::cout<<sortTest(&insertionSort,accending_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&insertionSort,accending_arr10000, num3)<<std::endl;
    std::cout<<sortTest(&insertionSort,accending_arr100000, num4)<<std::endl;

    std::cout<<"Selection Sort\n";

    std::cout<<sortTest(&selectionSort,accending_arr100, num1)<<std::endl;
    std::cout<<sortTest(&selectionSort,accending_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&selectionSort,accending_arr10000, num3)<<std::endl;
    //std::cout<<sortTest(&selectionSort,accending_arr100000, num4)<<std::endl;

    std::cout<<"Merge Sort\n";

    std::cout<<mergeSortTest(accending_arr100, num1)<<std::endl;
    std::cout<<mergeSortTest(accending_arr1000, num2)<<std::endl;
    std::cout<<mergeSortTest(accending_arr10000, num3)<<std::endl;
    std::cout<<mergeSortTest(accending_arr100000, num4)<<std::endl;

    std::cout<<std::endl;

    std::cout<<"Testing with few random array\n";
    std::cout<<"Insertion Sort\n";

    std::cout<<sortTest(&insertionSort,fewrandom_arr100, num1)<<std::endl;
    std::cout<<sortTest(&insertionSort,fewrandom_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&insertionSort,fewrandom_arr10000, num3)<<std::endl;
    //std::cout<<sortTest(&insertionSort,fewrandom_arr100000, num4)<<std::endl;

    std::cout<<"Selection Sort\n";

    std::cout<<sortTest(&selectionSort,fewrandom_arr100, num1)<<std::endl;
    std::cout<<sortTest(&selectionSort,fewrandom_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&selectionSort,fewrandom_arr10000, num3)<<std::endl;
    //std::cout<<sortTest(&selectionSort,fewrandom_arr100000, num4)<<std::endl;

    std::cout<<"Merge Sort\n";

    std::cout<<mergeSortTest(fewrandom_arr100, num1)<<std::endl;
    std::cout<<mergeSortTest(fewrandom_arr1000, num2)<<std::endl;
    std::cout<<mergeSortTest(fewrandom_arr10000, num3)<<std::endl;
    std::cout<<mergeSortTest(fewrandom_arr100000, num4)<<std::endl;

    std::cout<<std::endl;

    std::cout<<"Testing with ten random array\n";
    std::cout<<"Insertion Sort\n";

    std::cout<<sortTest(&insertionSort,tenrandom_arr100, num1)<<std::endl;
    std::cout<<sortTest(&insertionSort,tenrandom_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&insertionSort,tenrandom_arr10000, num3)<<std::endl;
    std::cout<<sortTest(&insertionSort,tenrandom_arr100000, num4)<<std::endl;

    std::cout<<"Selection Sort\n";

    std::cout<<sortTest(&selectionSort,tenrandom_arr100, num1)<<std::endl;
    std::cout<<sortTest(&selectionSort,tenrandom_arr1000, num2)<<std::endl;
    std::cout<<sortTest(&selectionSort,tenrandom_arr10000, num3)<<std::endl;
    //std::cout<<sortTest(&selectionSort,tenrandom_arr100000, num4)<<std::endl;

    std::cout<<"Merge Sort\n";

    std::cout<<mergeSortTest(tenrandom_arr100, num1)<<std::endl;
    std::cout<<mergeSortTest(tenrandom_arr1000, num2)<<std::endl;
    std::cout<<mergeSortTest(tenrandom_arr10000, num3)<<std::endl;
    std::cout<<mergeSortTest(tenrandom_arr100000, num4)<<std::endl;

    return 0;
}

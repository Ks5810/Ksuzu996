/*****************************************************************************
  Title          : SotingTests.cpp
  Author         : Keisuke Suzuki
  Created on     : November 28, 2018
  Description    : A implementation for SortingTests.hpp
  Purpose        : To implement the interface
  Modification   : made on Mar 20 2019 to some change to simplify the code
******************************************************************************/
//
#include "SortingTests.hpp"
#include <chrono>
#include <iostream>
#include <climits>

using namespace std::chrono;

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/

void selectionSort(int a[], size_t size){
    int max=INT_MAX;          //maximum value int can hold
    size_t index_to_change=0;
    
    for(size_t i=0;i<size;i++){
        int min=max;          //initialize min with current max
        for(size_t j=i; j<size;j++)
            if (a[j] <= min){
                min=a[j];
                index_to_change=j;
            }
        a[index_to_change]=a[i];
        a[i]=min;
    }
}

void insertionSort(int a[], size_t size){
        for(size_t i=0;i<size-1;i++){
            size_t j=i+1;
            while(a[j]<a[j-1]&&j>0){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                j--;
            }
        }
    }

/** merge() is a helper function for mergesort
  * @pram arr[]: pointer to the array
  * @pram from: index for first element of left array
  * @pram mid: index for the last element of left array
  * @pram to: index for the last element of right array
  * @precondition both left and right arrays are sorted
  * @postcondition arr[from] to arr[to] is sorted
  */
void merge(int arr[], int from, int mid, int to){

    int lArrSize=mid-from+1, rArrSize=to-mid;
    int arrIterator=from;  //iterator for resulting arr
    int lArrIterator=0;    //iterator for left array
    int rArrIterator=0;    //             right array
    
    //dinamically allocate left and right array to merge
    int *lArr=new int[lArrSize];
    int *rArr=new int[rArrSize];
    
    //deep copy each element from original array
    for(int i=0; i<lArrSize;i++) lArr[i]=arr[from+i];
    for(int i=0; i<rArrSize;i++) rArr[i]=arr[mid+1+i];
    
    //merge two arrays by getting smmaller element
    while(lArrIterator<lArrSize&&rArrIterator<rArrSize){
        if(lArr[lArrIterator]<=rArr[rArrIterator]){
            arr[arrIterator]=lArr[lArrIterator];
            arrIterator++; lArrIterator++;
        }
        else{
            arr[arrIterator]=rArr[rArrIterator];
            arrIterator++; rArrIterator++;
        }
    }
    //if left array still has elements
    while(lArrIterator<lArrSize){
        arr[arrIterator]=lArr[lArrIterator];
        arrIterator++; lArrIterator++;
    }
    //if right array still has elements
    while(rArrIterator<rArrSize){
        arr[arrIterator]=rArr[rArrIterator];
        arrIterator++; rArrIterator++;
    }
    // free memory
    delete[] lArr;
    delete[] rArr;
}


void mergeSort(int a[], int from, int to){
    //sort a by recursively calling this function
    
    //base case:return if from==to
    if(from<to){
        int mid=from+(to-from)/2;
        
        //sprit the array in hald and call mergesort for each of them
        mergeSort(a,from,mid);
        mergeSort(a,mid+1,to);
        
        //merge it from the top of runntime stack
        merge(a,from,mid,to);
    }
}




void generateRandomArray(int values[], size_t size){
    srand(static_cast<unsigned>(time(0)));  //use srand so that the
                                            //sequence become truly random
    for(int i=0; i<size; i++){
        auto some_random_variable= static_cast<int>(rand() % size);
        values[i]=some_random_variable;
    }
}

void generateAscendingArray(int values[], size_t size){
    generateRandomArray(values,size);
    mergeSort(values, 0, size-1);
}


void generateDescendingArray(int values[], size_t size){
    int *tempValues=new int[size];    //allocate temp array
    generateRandomArray(tempValues,size);
    mergeSort(tempValues,0,size-1);
    
    //copy temp array to values backwards
    for(size_t i=0;i<size;i++)
        values[i]=tempValues[size-1-i];
    delete[] tempValues;
    }

void generateLastTenRandomArray(int values[], size_t size){
    generateRandomArray(values,size);
    //sort upper size-11 elements
    mergeSort(values,0, size-11);
}

void generateFewRandomArray(int values[], size_t size){
     generateRandomArray(values,size);
     int intSize = (int) size;
     mergeSort(values,(intSize/10)+1,intSize-1);
     }




/*****************************************************************/
/****************** RUNTIME TEST FUNCTIONS ***********************/
/*****************************************************************/


double sortTest(void (*sortingFunction)(int a[], size_t size), 
                                            int values[], size_t size){

    double runtime_sum=0;
    
    //do same thing for ten times
    for(int i=0;i<10;i++){
        //copy the array so that the array is not sorted
        int *copy_array=new int[size];
        for(size_t j=0; j<size;j++)
            copy_array[j]=values[j];
        
        auto start_time = high_resolution_clock().now();  //start the clock
        sortingFunction(copy_array, size);
        auto end_time = high_resolution_clock::now();     //end the clock
        
        //get the time between start and end
        duration<float, std::micro> run_time = 
        duration_cast<microseconds>(end_time-start_time);  
        
        runtime_sum += run_time.count();

        delete[] copy_array;

        }
    double result=runtime_sum/10;    //get the average
    return result;
}



double mergeSortTest(int values[], size_t size){
    double runtime_sum=0;
    for(int i=0;i<10;i++){

        int *copy_array=new int[size];

        for(size_t j=0; j<size;j++)
            copy_array[j]=values[j];

        int intsize = static_cast<int>(size);

        auto start_time = high_resolution_clock().now();  //start clock
        mergeSort(copy_array, 0,intsize-1);
        auto end_time = high_resolution_clock::now();     //end clock
        duration<float, std::micro> run_time = duration_cast<microseconds>(end_time-start_time);
        runtime_sum += run_time.count();

        delete[] copy_array;
    }
    double result=runtime_sum/10;
    return result;
}






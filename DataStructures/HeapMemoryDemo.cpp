#include<iostream>
using namespace std;

int main()
{
    int a = 10; //stored in stack memory
    int *p = new int(); //allocate memory in heap dynamically
    *p = 10;

    delete(p); //deallocate memory, now p will become a dangling pointer!

    p=new int[4];

    delete[] p;
    p=NULL;
    return 0;
}

/**
 * This is a good example of Heap Memory through Dynamic Memory Allocation
 * Whenever we do DMA automatically Heap memory gets into use
 * Whenever we Allocate Memory through DMA Memory Does'nt get automatically deleted so we have to delete it manually
 * It is very Important to delete a allocated memory in Heap, because otherwise it will cause memory leak in the System
 * Mempry is taken as very bad situation, because it can become a big problem for systems like 'Server Systems' which never get turned off.
*/

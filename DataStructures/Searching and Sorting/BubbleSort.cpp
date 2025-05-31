#include <iostream>
using namespace std;
void print(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}

void bubble(int a[], int n)
{
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int i, j, temp;
    int a[5] = {45, 1, 32, 13, 26};
    int n = sizeof(a)/sizeof(a[0]);  // 20/4 = 5 
    cout << "Before Swapping: " << endl;
    print(a, n); // prints the original array
    bubble(a, n);
    cout << "\nAfter Swapping: " << endl;
    print(a, n); // prints the sorted array
    return 0;
}
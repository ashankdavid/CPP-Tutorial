#include <iostream>
using namespace std;

class Item
{
    private:
    int Id;
    float Price;

    public:
    void setData(int x, float y)
    {
        Id = x;
        Price = y;
    }

    void getData()
    {
        cout << "Item Id is: "<< Id << endl;
        cout << "Item Price is: "<< Price << endl;
    }
};

int main()
{
    int noOfItems,i,a;
    float b;
    cout << "Enter how many Items: ";
    cin >> noOfItems;
    Item *ptr = new Item[noOfItems];  //Creating an Array of Objects(noOfItems) using Pointers!
    Item *ptrTemp = ptr;  //Making ptrTemp points towards the 1st ptr

    for(i=0;i<noOfItems;i++) //Inputting the Details of Items using SetData()
    {
        cout << "Enter the Id and Price for Item " << i+1 << ": ";
        cin >> a >> b;
        ptr->setData(a,b);
        ptr++;
    }

    for(i=0;i<noOfItems;i++) // Printing the Data using GetData()
    {
        cout << "Details of Item " << i+1 << " is: " << endl;
        ptrTemp->getData();
        ptrTemp++;
    }
}
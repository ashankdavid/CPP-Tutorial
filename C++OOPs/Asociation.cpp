#include<iostream>
using namespace std;
class Information
{
public:
    int blockNo;
    int floorNo;
    int roomNo;
    int bedNo;

    Information(int blockNo, int floorNo, int roomNo, int bedNo)
    {
        this->blockNo = blockNo;
        this->floorNo = floorNo;
        this->roomNo = roomNo;
        this->bedNo = bedNo;
    }
};

class Payment
{
public:
    int regFees;
    int admissionFees;
    int balanceAmount;

    Payment(int regFees, int admissionFees, int balanceAmount)
    {
        this->regFees = regFees;
        this->admissionFees = admissionFees;
        this->balanceAmount = balanceAmount;
    }
};
class Patient
{
public:
    string patientName;
    int patientAge;
    string doa;
    string disease;
    Information * info;
    Payment * pay;

    Patient(string patientName, int patientAge, string doa, string disease, Information * info, Payment * pay)
    {
        this->patientName = patientName;
        this->patientAge = patientAge;
        this->doa = doa;
        this->disease = disease;
        this->info = info;
        this->pay = pay;
    }

    void printDetails()
    {
        cout << ".....Patient Details: ....." << endl;
        cout << "Patient Name: " << patientName << endl;
        cout << "Patient Age: " << patientAge << endl;
        cout << "Patient DOA" << doa << endl;
        cout << "Patient Disease" << disease << endl;
        cout << ".....Patient Information: ....." << endl;
        cout << "Block No: " << info->blockNo << endl;
        cout << "Floor No: " << info->floorNo << endl;
        cout << "Room No:" << info->roomNo << endl;
        cout << "Bed No: " << info->bedNo << endl;
        cout << ".....Patient Payment Info: ....." << endl;
        cout << "RegFees: " << pay->regFees << endl;
        cout << "Admission Fees: " << pay->admissionFees << endl;
        cout << "Balance Ammount " << pay->balanceAmount << endl;

    }

};



int main()
{
    Information info1(1, 1, 101, 1);
    Payment pay1(500,10000, 5000);
    Patient p1("Rahul", 20, "8th July", "Malaria", &info1, &pay1);
    p1.printDetails();

}
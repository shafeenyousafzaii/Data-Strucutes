#include <iostream>
#include <string>
using namespace std;
class Doctor
{
public:
    int id;
    string name;
    string specialization;

    Doctor(int id, string name, string specialization)
    {
        this->id = id;
        this->name = name;
        this->specialization = specialization;
    }
};

class Patient
{
public:
    string name;
    int age;
    string specialization;

    Patient(string name, int age, string specialization)
    {
        this->name = name;
        this->age = age;
        this->specialization = specialization;
    }
};

int main()
{
    Doctor doctors[8] = {
        Doctor(1, "Dr. John", "Cardiology"),
        Doctor(2, "Dr. Emma", "Dermatology"),
        Doctor(3, "Dr. Jack", "Gastroenterology"),
        Doctor(4, "Dr. Olivia", "Orthopedics"),
        Doctor(5, "Dr. Noah", "Pediatrics"),
        Doctor(6, "Dr. Ava", "Neurology"),
        Doctor(7, "Dr. William", "Ophthalmology"),
        Doctor(8, "Dr. Sophia", "Psychiatry")};

    Patient patients[15] = {
        Patient("Alice", 25, "Cardiology"),
        Patient("Bob", 35, "Dermatology"),
        Patient("Charlie", 40, "Gastroenterology"),
        Patient("David", 20, "Orthopedics"),
        Patient("Ethan", 15, "Pediatrics"),
        Patient("Grace", 30, "Neurology"),
        Patient("Henry", 45, "Ophthalmology"),
        Patient("Isabella", 55, "Psychiatry"),
        Patient("James", 18, "Cardiology"),
        Patient("Liam", 28, "Dermatology"),
        Patient("Mia", 38, "Gastroenterology"),
        Patient("Nora", 50, "Orthopedics"),
        Patient("Oliver", 12, "Pediatrics"),
        Patient("Penelope", 32, "Neurology"),
        Patient("Quinn", 22, "Ophthalmology")};

    int inputDoctorId;
    cout << "Enter a doctor ID: ";
    cin >> inputDoctorId;

    cout << "Patients for Doctor " << doctors[inputDoctorId - 1].name << ": " << endl;
    for (int i = 0; i < 15; i++)
    {
        if (patients[i].specialization == doctors[inputDoctorId - 1].specialization)
        {
            cout << patients[i].name << endl;
        }
    }

    string inputSpecialization;
    cout << "Enter a specialization name: ";
    cin >> inputSpecialization;

    cout << "Patients dealing with " << inputSpecialization << " doctors: " << endl;
    for (int i = 0; i < 15; i++)
    {
        if (patients[i].specialization == inputSpecialization)
        {
            cout << patients[i].name << " (" << patients[i].age << " years old)" << endl;
        }
    }

    int inputAge;
    cout << "Enter an age to find patients under that age: ";
    cin >> inputAge;

    cout << "Patients under " << inputAge << " years old: " << endl;
    for (int i = 0; i < 15; i++)
    {
        if (patients[i].age < inputAge)
        {
            cout << patients[i].name << " (" << patients[i].specialization << ")" << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random integer between min and max
int getRandomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to generate a random name
std::string generateRandomName()
{
    std::string names[] = {"John", "Alice", "Bob", "Eve", "Mary", "James", "Emma", "Michael", "Olivia", "William"};
    return names[getRandomInt(0, 9)];
}

class Doctor
{
public:
    Doctor(const std::string &doc_ID, const std::string &name, const std::string &specialty)
        : doc_ID(doc_ID), name(name), specialty(specialty) {}

    void addPatient(Patient &patient);
    void removePatient(Patient &patient);
    void listPatients();

private:
    std::string doc_ID;
    std::string name;
    std::string specialty;
    std::vector<Patient *> patients;
};

class Patient
{
public:
    Patient(const std::string &patient_ID, const std::string &name, int age)
        : patient_ID(patient_ID), name(name), age(age), doctor(nullptr) {}

    void assignDoctor(Doctor &doc);
    void discharge();

private:
    std::string patient_ID;
    std::string name;
    int age;
    Doctor *doctor;
};

// Implement Patient member functions
void Patient::assignDoctor(Doctor &doc)
{
    doctor = &doc;
    doc.addPatient(*this);
}

void Patient::discharge()
{
    if (doctor)
    {
        doctor->removePatient(*this);
        doctor = nullptr;
    }
}

// Implement Doctor member functions
void Doctor::addPatient(Patient &patient)
{
    patients.push_back(&patient);
}

void Doctor::removePatient(Patient &patient)
{
    for (size_t i = 0; i < patients.size(); ++i)
    {
        if (patients[i] == &patient)
        {
            patients.erase(patients.begin() + i);
            break;
        }
    }
}

void Doctor::listPatients()
{
    std::cout << "Patients of Dr. " << name << " (" << specialty << "):" << std::endl;
    for (const Patient *patient : patients)
    {
        std::cout << "- " << patient->name << " (Age: " << patient->age << ")" << std::endl;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr));

    std::vector<Doctor> doctors;
    std::vector<Patient> patients;

    // Generate 8 doctors with random data
    for (int i = 0; i < 8; ++i) {
        std::string doc_ID = "D" + std::to_string(i + 1);
        std::string name = generateRandomName();
        std::string specialties[] = {"Cardiologist", "Pediatrician", "Dermatologist", "Orthopedic", "Neurologist"};
        std::string specialty = specialties[getRandomInt(0, 4)];
        doctors.push_back(Doctor(doc_ID, name, specialty));
    }

    // Generate 15 patients with random data
    for (int i = 0; i < 15; ++i) {
        std::string patient_ID = "P" + std::to_string(i + 1);
        std::string name = generateRandomName();
        int age = getRandomInt(1, 100);
        patients.push_back(Patient(patient_ID, name, age));
    }

    // Assign patients to doctors
    for (Patient& patient : patients) {
        int doctorIndex = getRandomInt(0, 7);
        patient.assignDoctor(doctors[doctorIndex]);
    }

    // List patients for each doctor
    for (Doctor& doctor : doctors) {
        doctor.listPatients();
    }

    return 0;
}

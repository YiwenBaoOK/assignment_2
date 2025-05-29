#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
    vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        std::cerr << "Could not open file: " << file << std::endl;
        return patients;
    }

    std::string line;

    //This loop will read through line by line.
    while (getline(inFile, line)) {
        istringstream lineStream(line);
        string id, name, dobStr, diagnosis, vitalsRaw;

        //Adding prasing for the main fields shown in patient file.
        getline(lineStream, id, '|');
        getline(lineStream, name, '|');
        getline(lineStream, dobStr, '|');
        getline(lineStream, diagnosis, '|');
        getline(lineStream, vitalsRaw);

        //Parse the name in format (Lastname, Firstname)
        string lastName, firstName;
        istringstream nameStream(name);
        getline(nameStream, lastName, ',');
        getline(nameStream, firstName);

        //Parse date of birth
        tm dob = {};
        istringstream dobStream(dobStr);
        dobStream >> get_time(&dob, "%d-%m-%Y");

        //Create patient and adding diagnosis
        Patient* patient = new Patient(firstName, lastName, dob);
        patient->addDiagnosis(diagnosis);

        //Check if there is vital already, if yes, parse them.
        if (!vitalsRaw.empty()) {
            istringstream vitalsStream(vitalsRaw);
            string vitalsEntry;
            while (getline(vitalsStream, vitalsEntry, ';')) {
                istringstream entryStream(vitalsEntry);
                string btStr, hrStr, bpStr, rrStr;

                getline(entryStream, btStr, ',');
                getline(entryStream, hrStr, ',');
                getline(entryStream, bpStr, ',');
                getline(entryStream, rrStr);

                float bt = stof(btStr);
                int hr = stoi(hrStr);
                int bp = stoi(bpStr);
                int rr = stoi(rrStr);

                Vitals* vitals = new Vitals(bt, bp, hr, rr);
                patient->addVitals(vitals);
            }


        }
        //Finally add the patient to the vector.
        patients.push_back(patient);

    }
    inFile.close();
    return patients;


       
}

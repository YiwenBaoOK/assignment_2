#include "PatientFileLoaderAdapter.h"
#include <iostream>

PatientFileLoaderAdapter::PatientFileLoaderAdapter(const std::string& filePath)
    : _filePath(filePath) {
}

void PatientFileLoaderAdapter::initialiseConnection() {
    // No actual initialization needed for file loading
    std::cout << "Attempting to initialize with file: " << _filePath << std::endl;
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn) {
    // Use the existing PatientFileLoader to load patients
    std::cout << "Loading patients from file: " << _filePath << std::endl;


    auto loadedPatients = _fileLoader.loadPatientFile(_filePath);

    std::cout << "Loaded " << loadedPatients.size() << " patients" << std::endl;


    patientIn.insert(patientIn.end(), loadedPatients.begin(), loadedPatients.end());
}

void PatientFileLoaderAdapter::closeConnection() {
    // No cleanup needed for file loading
}
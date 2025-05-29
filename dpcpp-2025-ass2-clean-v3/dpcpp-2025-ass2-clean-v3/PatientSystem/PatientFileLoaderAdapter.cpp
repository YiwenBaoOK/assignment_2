#include "PatientFileLoaderAdapter.h"
#include <iostream>

PatientFileLoaderAdapter::PatientFileLoaderAdapter(const std::string& filePath)
    : _filePath(filePath) {
}

void PatientFileLoaderAdapter::initialiseConnection() {
    // No actual initialization needed for file loading
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn) {
    // Use the existing PatientFileLoader to load patients
    auto loadedPatients = _fileLoader.loadPatientFile(_filePath);
    patientIn.insert(patientIn.end(), loadedPatients.begin(), loadedPatients.end());
}

void PatientFileLoaderAdapter::closeConnection() {
    // No cleanup needed for file loading
}
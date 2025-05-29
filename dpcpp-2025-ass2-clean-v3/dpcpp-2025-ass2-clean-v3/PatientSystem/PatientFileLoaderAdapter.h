#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"
#include <string>

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {
public:
    PatientFileLoaderAdapter(const std::string& filePath);

    // Implement the AbstractPatientDatabaseLoader interface
    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientIn) override;
    virtual void closeConnection() override;

private:
    PatientFileLoader _fileLoader;
    std::string _filePath;
};
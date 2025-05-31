#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include <vector>
#include <memory>

// Composite pattern implementation that can combine both patient loaders (from database and from text file)
class CompositePatientLoader : public AbstractPatientDatabaseLoader {
public:
    CompositePatientLoader();
    virtual ~CompositePatientLoader();

    // Add a loader to the composite
    // The order of addition determines the order of execution
    // Ownership of the loader is transferred to the composite
    void addLoader(AbstractPatientDatabaseLoader* loader);

    // Inherited from AbstractPatientDatabaseLoader
    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientIn) override;
    virtual void closeConnection() override;

private:
    // Vector of loaders that will be executed in sequence
    std::vector<AbstractPatientDatabaseLoader*> _loaders;
};


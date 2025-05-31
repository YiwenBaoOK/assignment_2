#include "CompositePatientLoader.h"

CompositePatientLoader::CompositePatientLoader() {
}

CompositePatientLoader::~CompositePatientLoader() {
    // Clean up all loaders
    for (auto loader : _loaders) {
        delete loader;
    }
}

void CompositePatientLoader::addLoader(AbstractPatientDatabaseLoader* loader) {
    // Add a loader to the composite
    _loaders.push_back(loader);
}

void CompositePatientLoader::initialiseConnection() {
    // Initialize all contained loaders in sequence
    for (auto loader : _loaders) {
        loader->initialiseConnection();
    }
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn) {
    // Load patients from all contained loaders in sequence
    for (auto loader : _loaders) {
        loader->loadPatients(patientIn);
    }
}

void CompositePatientLoader::closeConnection() {
    // Close connections for all contained loaders in sequence
    for (auto loader : _loaders) {
        loader->closeConnection();
    }
}


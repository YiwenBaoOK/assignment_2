#include "CordycepsBrainInfectionCalculator.h"
#include "Patient.h"
#include "Vitals.h"

AlertLevel CordycepsBrainInfectionCalculator::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    int respiratoryRate = vitals.RR();

    // Cordyceps Brain Infection algorithm based on Respiratory Rate (RR)
    if (respiratoryRate > 40) {
        return AlertLevel::Red;
    }
    else if (respiratoryRate > 30) {
        return AlertLevel::Orange;
    }
    else if (respiratoryRate > 20) {
        return AlertLevel::Yellow;
    }
    else {
        return AlertLevel::Green;
    }
}


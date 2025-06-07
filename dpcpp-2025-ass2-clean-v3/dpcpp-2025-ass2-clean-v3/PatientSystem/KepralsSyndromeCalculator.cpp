#include "KepralsSyndromeCalculator.h"
#include "Patient.h"
#include "Vitals.h"

AlertLevel KepralsSyndromeCalculator::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    // Cordyceps Brain Infection algorithm based on Age and Heart Rate(HR)
    int heartRate = vitals.HR();
    int patientAge = patient.age();  // This gets the calculated age

    // Kepral's Syndrome algorithm
    if ((patientAge < 12 && heartRate > 120) || (patientAge >= 12 && heartRate > 100)) {
        return AlertLevel::Red;
    }
    else {
        return AlertLevel::Green;
    }
}


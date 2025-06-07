#include "AndromedaStrainCalculator.h"
#include "Patient.h"
#include "Vitals.h"

AlertLevel AndromedaStrainCalculator::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    int bloodPressure = vitals.BP();

    // Cordyceps Brain Infection algorithm based on Respiratory Rate (RR)
    if (bloodPressure > 140) {
        return AlertLevel::Red;
    }
    else if (bloodPressure > 130) {
        return AlertLevel::Orange;
    }
    else if (bloodPressure > 110) {
        return AlertLevel::Yellow;
    }
    else {
        return AlertLevel::Green;
    }
}


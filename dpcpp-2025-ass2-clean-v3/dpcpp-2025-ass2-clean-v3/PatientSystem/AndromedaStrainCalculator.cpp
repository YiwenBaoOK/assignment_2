#include "AndromedaStrainCalculator.h"
#include "Patient.h"
#include "Vitals.h"

AlertLevel AndromedaStrainCalculator::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    int bloodPressure = vitals.BP();

    // Andromeda Strain's algorithm based on Blood Pressure (BP)
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


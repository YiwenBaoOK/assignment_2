#pragma once

#include "PatientAlertLevels.h"

// forward declarations
class Patient;
class Vitals;

// Strategy pattern interface for calculating alert levels
class AlertLevelCalculator {
public:
    virtual ~AlertLevelCalculator() = default;
    virtual AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const = 0;
};


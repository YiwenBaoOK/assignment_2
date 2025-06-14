#pragma once

// Forward declaration
class Patient;

// Observer interface for the Observer pattern
// All notification systems should implement this interface
class AlertObserver {
public:
    virtual ~AlertObserver() = default;

    // Called when a patient's alert level changes
    virtual void onAlertLevelChanged(Patient* patient) = 0;
};


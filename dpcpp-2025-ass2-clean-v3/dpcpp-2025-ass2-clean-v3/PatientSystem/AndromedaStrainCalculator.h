#pragma once
#include "AlertLevelCalculator.h"

class AndromedaStrainCalculator : public AlertLevelCalculator {
public:
    AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const override;
};
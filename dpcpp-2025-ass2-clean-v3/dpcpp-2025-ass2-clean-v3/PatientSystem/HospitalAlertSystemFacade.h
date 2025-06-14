#pragma once

#include "Patient.h"
#include "RedAlertObserver.h"


class HospitalAlertSystemFacade : public RedAlertObserver{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	void sendAlertForPatient(Patient* p);

	//Implement the Alert interface
	void AlertLevelChanged(Patient* patient) override;
};


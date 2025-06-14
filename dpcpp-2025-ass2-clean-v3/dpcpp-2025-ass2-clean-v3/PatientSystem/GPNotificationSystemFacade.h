#pragma once

#include "Patient.h"
#include "RedAlertObserver.h"


class GPNotificationSystemFacade : public RedAlertObserver {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);

	//Implement the Alert interface
	void AlertLevelChanged(Patient* patient) override;
};


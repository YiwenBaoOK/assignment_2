#include "Patient.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Vitals.h"
#include "CordycepsBrainInfectionCalculator.h"
#include "KepralsSyndromeCalculator.h"
#include "AndromedaStrainCalculator.h"

using namespace std;

const std::string Diagnosis::CORDYCEPS_BRAIN_INFECTION = "Cordyceps Brain Infection";
const std::string Diagnosis::KEPRALS_SYNDROME = "Kepral's Syndrome";
const std::string Diagnosis::ANDROMEDA_STRAIN= "Andromeda Strain";


Patient::Patient(const std::string& firstName, const std::string& lastName, std::tm birthday) :
	Person(firstName, lastName, birthday),
	_alertLevel(AlertLevel::Green)
{
}

int Patient::age() const
{	
	// an inaccurate age estimate but fine for assignment purposes
	return 2022 - (1900 + _birthday.tm_year);
}

std::string Patient::uid() const
{
	std::stringstream ss;
	ss << (char)std::tolower(_lastName.at(0)) 
	   << (char)std::tolower(_firstName.at(0))
	   << std::setfill('0') << std::setw(2) << (_birthday.tm_mon + 1) 
	   << _birthday.tm_year;
	return ss.str();
}

std::string Patient::humanReadableID() const
{
	return "" + _lastName + ", " + _firstName + " (" + uid() + ")";
}

std::ostream& operator<<(std::ostream& os, const Patient& p)
{
	os << p.uid() << "|" << p._lastName << "," << p._firstName << "|" << std::put_time(&p._birthday, "%d-%m-%Y") << "|" << p.primaryDiagnosis();
	
	os << "|";
	for (int i = 0; i < p.vitals().size(); ++i) {
		auto v = p.vitals()[i];
		os << *v;
		if (i != p.vitals().size() - 1) {
			os << ";";
		}
	}
	return os;
}

void Patient::addDiagnosis(const std::string& diagnosis)
{
	_diagnosis.push_back(diagnosis);
}

const std::string& Patient::primaryDiagnosis() const
{
	return _diagnosis.front();
}

void Patient::addVitals(const Vitals* v)
{
	_vitals.push_back(v);
	// TODO: calculate alert levels
	//This makes sure that only new vitals will be calculated
	if (_alertCalculator && v != nullptr) {
		AlertLevel newLevel = _alertCalculator->calculateAlertLevel(*this, *v);
		setAlertLevel(newLevel);
	}

}

const std::vector<const Vitals*> Patient::vitals() const
{
	return _vitals;
}

void Patient::setAlertLevel(AlertLevel level)
{
	_alertLevel = level;

	if (_alertLevel > AlertLevel::Green) {
		cout << "Patient: " << humanReadableID() << "has an alert level: ";
		switch (_alertLevel) {
		case AlertLevel::Yellow:
			cout << "Yellow";
			break;
		case AlertLevel::Orange:
			cout << "Orange";
			break;
		case AlertLevel::Red:
			cout << "Red";
			alertSubscribers();
			break;
		}
		cout << endl;
	}
}

void Patient::AlertCalculation(std::unique_ptr<AlertLevelCalculator> calculator)
{
	//The patient can use it to do calculations of alert levels.
	_alertCalculator = std::move(calculator);

}

void Patient::addSubscriber(RedAlertObserver* subscriber)
{
	if (subscriber != nullptr) {
		_subscribers.push_back(subscriber);
}
}

void Patient::removeSubscriber(RedAlertObserver* subscriber)
{	//This can loop through the vector with effciency
	for (auto it = _subscribers.begin(); it != _subscribers.end(); ++it) {
		if (*it == subscriber) {     // Finding the subscriber that would like to remove
			_subscribers.erase(it); // remove the subscriber
			break;					// exit after remove the subscriber to avoid iterator invalidation
		}
}
}

void Patient::alertSubscribers()
{
	for (RedAlertObserver* subscriber : _subscribers) {
		if (subscriber != nullptr) {
			subscriber->onAlertLevelChanged(this);
		}
}
}

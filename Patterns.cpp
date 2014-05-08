#include "Patterns.h"

Singleton* Singleton::instance = NULL;

Singleton::Singleton() {}

Singleton::~Singleton() {}

Singleton* Singleton::get_singleton() {
	if(instance == NULL) {
		std::cout << "new instance" << std::endl;
		instance = new Singleton();
		return instance;
	}
	std::cout << "existing instance" << std::endl;
	return instance;
}

Subject::Subject() {}

Subject::~Subject() {}
	
void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}

void Subject::dettach(Observer* observer) {
	std::vector<Observer*>::iterator iter;
	iter = std::find(observers.begin(), observers.end(), observer);
	observers.erase(iter);
}

void Subject::notify() {
	for(int i = 0; i < observers.size(); i++) {
		observers[i]->update(this);
	}
}

ClockTime::ClockTime() : 
  Subject() {
    _strtime(temp);
}

int ClockTime::get_hours() {
	char timebuf[128];
	std::strncpy(timebuf, temp, 2);
	timebuf[2] = NULL;
	return std::atoi(timebuf);
}

int ClockTime::get_minutes() {
	char timebuf[128];
	std::strncpy(timebuf, temp+3, 2);
	timebuf[2] = NULL;
	return std::atoi(timebuf);
}

int ClockTime::get_seconds() {
	char timebuf[128];
	std::strncpy(timebuf, temp+6, 2);
	timebuf[2] = NULL;
	return std::atoi(timebuf);
}

void ClockTime::tick() {
	_tzset();
	_strtime(temp);
	notify();
}

DigitalClock::DigitalClock(ClockTime* clock_time) : 
  Observer() {
	digital_clock = clock_time;
	digital_clock->attach(this);
}

DigitalClock::~DigitalClock() {
	digital_clock->dettach(this);
}

void DigitalClock::update(Subject* subject) {
	if(digital_clock == subject)
		this->draw();
}

void DigitalClock::draw() {
	int hours = digital_clock->get_hours();
	int minutes = digital_clock->get_minutes();
	int seconds = digital_clock->get_seconds();

	std::cout << "Digital time is " << hours << " : " << minutes << " : " << seconds << std::endl;
}

AnalogClock::AnalogClock(ClockTime* clock_time) :
  Observer() {
    analog_clock = clock_time;
	analog_clock->attach(this);
}

AnalogClock::~AnalogClock() {
	analog_clock->dettach(this);
}

void AnalogClock::update(Subject* subject) {
	if(analog_clock == subject)
		this->draw();
}

void AnalogClock::draw() {
	int hours = analog_clock->get_hours();
	int minutes = analog_clock->get_minutes();
	int seconds = analog_clock->get_seconds();

	std::cout << "Analog time is " << hours << " : " << minutes << " : " << seconds << std::endl;
}
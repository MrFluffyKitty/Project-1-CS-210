// SNHU
// cs-210-T4445
// Programming Languages
// Tristin Watson

#include <iostream>
#include <vector>
#include <string>

class setClock {
private:
	int hour;
	int minute;
	int second;
	int hour2;
	std::string ampm = "am";
	std::string clock1;
	std::string clock2;
public:
	// mutated constructor.
	setClock(int aHour, int aMinute, int aSecond, int aHour2) {
		setHour(aHour);
		setMinute(aMinute);
		setSecond(aSecond);
		setHour2(aHour2);
		if (this->getHour() > 11) {
			ampm = "pm";
		}
	}
	setClock() {

	}
	// getters and setters.
	int getHour() {
		return hour;
	}
	void setHour(int aHour) {
		hour = aHour;
	}
	int getHour2() {
		return hour2;
	}
	void setHour2(int aHour2) {
		hour2 = aHour2;
	}
	int getMinute() {
		return minute;
	}
	void setMinute(int aMinute) {
		minute = aMinute;
	}
	int getSecond() {
		return second;
	}
	void setSecond(int aSecond) {
		second = aSecond;
	}
	virtual std::string toString() {
		return std::to_string(this->getHour()) + ":" + std::to_string(this->getMinute()) + ":" + std::to_string(this->getSecond());
	}
	virtual std::string toString2() {
		return std::to_string(this->getHour2()) + ":" + std::to_string(this->getMinute()) + ":" + std::to_string(this->getSecond()) + " " + ampm;
	}
};
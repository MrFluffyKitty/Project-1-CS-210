// SNHU
// cs-210-T4445
// Programming Languages
// Tristin Watson

#include <iostream>
#include <vector>
#include <string>
#include "Constructor.cpp"

// setClock class.
std::vector<setClock> theClocks;
// menu display method.

void displayMenu() {
	std::cout << "\nMenu Options are: \n";
	std::cout << "[1] Change the time.\n";
	std::cout << "[2] Display current time.\n";
	std::cout << "[3] Add a second. (Does not work).\n";
	std::cout << "[q] to quit the program.\n";
	std::cout << "Please enter a selection\n\n";
}

// clock settings method.
void clockSettings() {
	// variables.
	std::string userInput;
	int hour;
	int hour2;
	int minute;
	int second;
	// set hour.
	std::cout << "Please input the hour: \nIf you do not need to change the hour, type 'no'.\n";
	while (true) {
		std::cin >> userInput;
		if (userInput == "no" || userInput == "No") {
			hour = 1;
			break;
		}
		try {
			hour = std::stoi(userInput);
			if (hour < 0 || hour > 23) {
				std::cout << "That hour is not possible.\n";
				std::cout << "Please try another hour.\n";
			}
			else {
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// set minutes.
	std::cout << "Please input the minutes: \nIf you do not need to change the minutes, type 'no'.\n";
	while (true) {
		std::cin >> userInput;
		if (userInput == "no" || userInput == "No") {
			minute = 1;
			break;
		}
		try {
			minute = stoi(userInput);
			if (minute < 0 || minute > 59) {
				std::cout << "That minute is not possible.\n";
				std::cout << "Please try another minute.\n";
			}
			else {

				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// set seconds.
	std::cout << "Please input the seconds: \nIf you do not need to change the seconds, type 'no'.\n";
	while (true) {
		std::cin >> userInput;
		if (userInput == "no" || userInput == "No") {
			second = 1;
			break;
		}
		try {
			second = stoi(userInput);
			if (second < 0 || second > 59) {
				std::cout << "That second is not possible.\n";
				std::cout << "Please try another second.\n";
			}
			else {
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// set clocks.
	theClocks.clear();
	setClock theClock;
	theClock.setHour(hour), theClock.setMinute(minute), theClock.setSecond(second), theClock.setHour2(hour);
	std::cout << "\nCurrent time: \n24 hour clock - " << theClock.toString() << " " << std::endl;
	if (theClock.getHour() > 12) {
		theClock.setHour2(theClock.getHour() - 12);
	}
	else {
		theClock.setHour2(theClock.getHour());
	}
	std::cout << "12 hour clock - " << theClock.toString2() << " " << std::endl;
	theClocks.push_back(theClock);
}

// add Second.
void addSecond() {
	for (setClock theClock : theClocks) {
		theClock.setSecond(theClock.getSecond() + 1);
		break;
	}
}

// sets up clock.
void initializeClock() {
	setClock theClock(15, 15, 45, 3);
	theClocks.push_back(theClock);
}

// display time.
void displayTime() {
	for (setClock theClock : theClocks) {
		std::cout << "\nCurrent time: \n24 hour clock - " << theClock.toString() << " " << std::endl;
		std::cout << "12 hour clock - " << theClock.toString2() << " " << std::endl;
		break;
	}
}

int main() {
	// while true loop for menu.
	bool run = true;
	initializeClock();
	displayTime();
	std::cout << "\n\n\t\tWelcome to Chada Tech!\n";
	while (run) {
		std::string userInput;
		displayMenu();
		std::cin >> userInput;
		if (userInput == "1") {
			clockSettings();
		}
		else if (userInput == "2") {
			displayTime();
		}
		else if (userInput == "3") {
			addSecond();
		}
		else if (userInput == "q" || userInput == "Q") {
			run = false;
			std::cout << "\nThank you and have a nice day!\n\n";
		}
		else {
			std::cout << "\nIncorrect input.";
		}
	}
	return 0;
}
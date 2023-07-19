#pragma once
#include <iostream>
#include <chrono>

class Timer {
public:
	int delayType;  // 0 - milisec, 1 - sec, 2 - min
	bool timerPassed, started, stopped;
	int delay, timePassed, deltaTime, prevTime;

	Timer();
	void setTimerSec(int sec);
	void setTimerMilisec(int ms);
	void setTimerMin(int min);
	void update();
	void start();
	void stop();
};
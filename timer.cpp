#include "timer.h"

Timer::Timer()
{
	started = false;
	stopped = true;
}

void Timer::setTimerSec(int sec)
{
	delayType = 1;
	delay = sec * 1000;
}

void Timer::setTimerMilisec(int ms)
{
	delayType = 1;
	delay = ms;
}

void Timer::setTimerMin(int min)
{
	delayType = 1;
	delay = min * 60000;
}

void Timer::update()
{
	if (starting)
	{
		auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		prevTime = millisec;

		starting = false;
	}

	if (started)
	{
		auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		deltaTime = millisec - prevTime;
		prevTime = millisec;
		timePassed += deltaTime;
		//std::cout << timePassed << std::endl;

		if (timePassed >= delay)
		{
			//std::cout << "passed timer, timePassed: " << timePassed << " delay: " << delay << std::endl;


			stop();
		}
	}

}

void Timer::start()
{
	stop();
	started = true;
	stopped = false;

	//std::cout << "started timer, delay: " << delay << std::endl;

	//auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	//prevTime = millisec;

	starting = true;
}

void Timer::stop()
{
	started = false;
	stopped = true;
	deltaTime = 0;
	prevTime = 0;
	timePassed = 0;
}
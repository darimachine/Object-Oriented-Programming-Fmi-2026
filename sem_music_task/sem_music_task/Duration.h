#pragma once
class Duration
{
private:
	unsigned int minutes;
	unsigned int seconds;
public:
	Duration();
	Duration(unsigned int minutes, unsigned int seconds);
	unsigned int totalSeconds() const;
	unsigned int getMinutes() const;
	unsigned int getSeconds() const;
	void setMinutes(unsigned int minutes);
	void setSeconds(unsigned int seconds);
	void setDuration(unsigned int minutes, unsigned int seconds);
};


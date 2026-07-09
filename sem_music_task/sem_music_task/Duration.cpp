#define _CRT_SECURE_NO_WARNINGS
#include "Duration.h"
#include <iostream>

Duration::Duration() : minutes(0), seconds(0) 
{

}
Duration::Duration(unsigned int minutes, unsigned int seconds) 
{
    this->minutes = minutes;
    if (seconds >= 60) 
    {
        this->minutes += seconds / 60;
        this->seconds = seconds % 60;
    }
    else 
    {
        this->seconds = seconds;
    }
}
unsigned int Duration::totalSeconds() const
{
    return minutes * 60 + seconds;
}
unsigned int Duration::getMinutes() const 
{ 
    return minutes;
}
unsigned int Duration::getSeconds() const
{
    return seconds;
}
void Duration::setMinutes(unsigned int minutes)
{
    this->minutes = minutes;
}
void Duration::setSeconds(unsigned int seconds)
{ 
    this->seconds = seconds;
}
void Duration::setDuration(unsigned int minutes, unsigned int seconds) 
{ 
    this->minutes = minutes;
    this->seconds = seconds; 
}
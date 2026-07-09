#include "Duration.h"

Duration::Duration():minutes(0), seconds(0)
{

}

Duration::Duration(unsigned int m, unsigned int s)
{
	minutes = m + s / 60;
	seconds = s % 60;
}

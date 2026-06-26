#include "VehicleList.h"

VehicleList::VehicleList()
{
	VehicleList** vehicleList = new VehicleList*[5];
	for (int i = 0;i < 5;i++) {
		vehicleList[i] = new Vehicle();
	}
}

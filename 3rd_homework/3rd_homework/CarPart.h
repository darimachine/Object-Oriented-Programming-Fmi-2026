#pragma once
#include <string>
class CarPart
{
	private:
		static unsigned ID;
		unsigned partID;
		std::string manifacturerName;
		std::string description;

	public:
		CarPart(const std::string& inpMName, const std::string& inpDesc);

		friend std::ostream& operator<<(std::ostream& os, const CarPart& obj);
		virtual void print(std::ostream& os) const;
		
		virtual ~CarPart() = default;
};


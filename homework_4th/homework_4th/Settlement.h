	#pragma once
	#include "Landmark.h"
	class Settlement : public Landmark
	{
		private:
			unsigned int population;

		public:
			Settlement(const std::string& inpName, const Coordinates& inpCoords, unsigned int inpThreat,
				unsigned int inpPopulation);

			std::string getType() const override;
			void print() const override;
	};


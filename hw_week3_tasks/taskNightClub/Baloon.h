#pragma once

enum class BalloonColor
{
	WHITE,
	GREEN,
	RED,
	COUNT
};

class Baloon
{
private:
	double price;
	BalloonColor color;
	public:
		Baloon();
		Baloon(double price, BalloonColor color);
		double getPrice() const;
		BalloonColor getColor() const;
		void setPrice(double price);
		void setColor(BalloonColor color);
		static BalloonColor colorFromString(const char* s);
		static const char* colorToString(BalloonColor c);
};


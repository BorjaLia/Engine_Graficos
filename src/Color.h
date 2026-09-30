#pragma once

namespace utils
{
	struct Color
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;

		Color()
		{
			this->r = 255;
			this->g = 255;
			this->b = 255;
			this->a = 255;
		}

		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		Color(unsigned char r, unsigned char g, unsigned char b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = 255;
		}

		static Color red() { return Color(255, 0, 0); }
		static Color green() { return Color(0, 255, 0); }
		static Color blue() { return Color(0, 0, 255); }

		static Color yellow() { return Color(255, 255, 0); }

		static Color white() { return Color(255, 255, 255); }
		static Color black() { return Color(0, 0, 0); }

	};
}
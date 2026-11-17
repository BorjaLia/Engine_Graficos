#pragma once

namespace utils
{
	struct Color
	{
		float r;
		float g;
		float b;
		float a;

		Color()
		{
			this->r = 1;
			this->g = 1;
			this->b = 1;
			this->a = 1;
		}

		Color(float r, float g, float b, float a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		Color(float r, float g, float b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = 1;
		}

		static Color red() { return Color(1, 0, 0); }
		static Color green() { return Color(0, 1, 0); }
		static Color blue() { return Color(0, 0, 1); }

		static Color yellow() { return Color(1, 1, 0); }
		static Color pink() { return Color(1, 0, 1); }

		static Color white() { return Color(1, 1, 1); }
		static Color black() { return Color(0, 0, 0); }
	};
}
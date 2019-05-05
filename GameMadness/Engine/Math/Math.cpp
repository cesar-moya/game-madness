#include "Math.h"
#include <math.h>

namespace Math {
	double ConvertToRadians(double degrees) {
		return (degrees * PI) / 180;
	}

	double ConvertToDegrees(double radians) {
		return (radians * 180) / PI;
	}
	
	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot) {
		//we take the rotation in degrees and convert it to radians
		double radRot = ConvertToRadians(rot); 
		//cos and sin of the rotation in radians (at THAT theta)
		double s = sin(radRot);
		double c = cos(radRot);

		//to rotate it, we "move the point back" to the center, then rotate it, then "move the point back" to its position
		point = point - pivot; //we get the point at pivot
		
		//TODO: study cos and sin
		float newX = (float)(point.x * c - point.y * s);
		float newY = (float)(point.x * s + point.y * c);

		//since we subtracted pivot before, we need to add it back
		point.x = newX + pivot.x;
		point.y = newY + pivot.y;

		return point;
	}

	float Math::Min(vector<float> x) {
		float min = x[0];
		for (int i = 1; i < x.size(); i++) {
			if (x[i] < min)
				min = x[i];
		}
		return min;
	}
	
	float Math::Max(vector<float> x) {
		float max = x[0];
		for (int i = 1; i < x.size(); i++) {
			if (x[i] > max)
				max = x[i];
		}
		return max;
	}
}
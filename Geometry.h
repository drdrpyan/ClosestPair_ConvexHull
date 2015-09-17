#ifndef ___BGM__GEOMETRY__H__
#define ___BGM__GEOMETRY__H__

#include "Point2D.h"
#include <cmath>
using BGM::TYPE::Point2D;

namespace BGM
{
namespace GEOMETRY
{

template<typename NumType>
float computeDistance(const Point2D<NumType>& p1, const Point2D<NumType>& p2)
{
	return sqrt( (p1.X()-p2.X())*(p1.X()-p2.X()) + (p1.Y()-p2.Y())*(p1.Y()-p2.Y()) );
}

template<typename NumType>
float computeTheta(const Point2D<NumType>& from, const Point2D<NumType>& to)
{
	int dx = to.X() - from.X();
	int dy = to.Y() - from.Y();
	int absX = (dx>0) ? dx : -dx;
	int absY = (dy>0) ? dy : -dy;

	float t = (absX+absY == 0) ? 0 : (float)dy/(float)(absX+absY);
	if(dx < 0)
		t = 2.0f - t;
	else if(dy < 0)
		t = 4.0f + t;

	return t*90.0f;
}

template<typename NumType>
const NumType crossProduct(const Point2D<NumType>& lhs, const Point2D<NumType>& rhs)
{
	return lhs.X()*rhs.Y() - rhs.X()*lhs.Y();
}

template<typename NumType>
bool isRightCurve(const Point2D<NumType>& from, const Point2D<NumType>& via, const Point2D<NumType>& to)
{
	return crossProduct(via-from, to-from) < 0;
}


}
}

#endif

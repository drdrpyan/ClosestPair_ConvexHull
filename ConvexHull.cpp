#include "ConvexHull.h"
#include "Geometry.h"
#include <utility>
#include <algorithm>

using std::pair;
using std::sort;
using std::vector;
using std::list;
using BGM::GEOMETRY::computeTheta;
using BGM::GEOMETRY::isRightCurve;

struct theta_less
{
	static Point pivot;
	inline bool operator()(const Point *lhs, const Point *rhs)
	{
		return computeTheta(pivot, *lhs) < computeTheta(pivot, *rhs);
	}
};
Point theta_less::pivot = Point(0,0);

void ConvexHull::initConvexHull(const vector<Point>& pointList, list<Point*>& convexHull) const
{
	convexHull.push_back(new Point(pointList[0]));
	list<Point*>::iterator lowestPoint = convexHull.begin();

	for(unsigned int i=1; i<pointList.size(); i++)
	{
		convexHull.push_back(new Point(pointList[i]));
		if((*lowestPoint)->Y() > convexHull.back()->Y())
			(lowestPoint = convexHull.end())--;
	}

	theta_less::pivot = *(*lowestPoint);
	convexHull.sort(theta_less());
}

void ConvexHull::delNonConvexHullPoint(list<Point*>& convexHull) const
{
	list<Point*>::iterator before, current, forward;
	before = convexHull.begin();
	(current = before)++;
	(forward = current)++;

	if(current==convexHull.end() || forward==convexHull.end())
		return;

	while(forward != convexHull.end())
	{
		if(isRightCurve(*(*before), *(*current), *(*forward)))
		{
			convexHull.erase(current);
			current = before;
			if(before!=convexHull.begin())
				before--;
		}
		else
		{
			before++;
			current++;
			forward++;
		}
	}
}

list<Point*>* ConvexHull::getConVexHull(const vector<Point>& pointList) const
{
	//exception
	if(pointList.size() == 0)
		return 0;

	list<Point*> *convexHull = new list<Point*>;
	initConvexHull(pointList, *convexHull);
	delNonConvexHullPoint(*convexHull);

	return convexHull;
}

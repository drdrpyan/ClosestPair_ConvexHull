#include "ClosestPair.h"
#include "Geometry.h"
#include <algorithm>
#include <iostream>

using std::pair;
using std::vector;
using std::sort;
using BGM::GEOMETRY::computeDistance;

//std::ostream& operator<<(std::ostream& os, const Point& p)
//{
//	os << '(' << p.X() << ',' << p.Y() << ')';
//	return os;
//}

pair<Point, Point> ClosestPair::getClosestPair(const vector<Point>& pointList, vector<Point>::iterator beg, vector<Point>::iterator end) const
{
	pair<Point, Point> closestPair;

	//end recursion
	if(end-beg == 2)
		closestPair = pair<Point, Point>(*beg, *end);
	else if(end-beg == 3)
	{
		float d1 = computeDistance(*beg, *(beg+1));
		float d2 = computeDistance(*beg, *(end-1));
		float d3 = computeDistance(*(beg+1), *(end-1));

		if(d1>=d2 && d1>=d3)
			closestPair = pair<Point, Point>(*beg, *(beg+1));
		else if(d2>=d1 && d2>=d3)
			closestPair = pair<Point, Point>(*beg, *(end-1));
		else
			closestPair = pair<Point, Point>(*(beg+1), *end);
	}
	//recursion
	else
	{
		//divide
		vector<Point>::iterator mid = beg+((end-beg)/2);
		pair<Point, Point> pair1 = getClosestPair(pointList, beg, mid);
		pair<Point, Point> pair2 = getClosestPair(pointList, mid, end);

		//merge
		if(computeDistance(pair1.first, pair1.second) < computeDistance(pair2.first, pair2.second))
			closestPair = pair1;
		else
			closestPair = pair2;
		float closestDistance = computeDistance(closestPair.first, closestPair.second);

		vector<Point> closeToMid;
		for(vector<Point>::iterator itr=mid; itr>=beg && (itr->X())>((float)(mid->X())-closestDistance); itr--)
			closeToMid.push_back(*itr);
		for(vector<Point>::iterator itr=mid+1; itr<end && (itr->X())<((float)(mid->X())+closestDistance); itr++)
			closeToMid.push_back(*itr);

		sort(closeToMid.begin(), closeToMid.end(), Point::less_Y);
		float newDistance;
		for(unsigned int i=0; i<closeToMid.size(); i++)
			for(unsigned int j=i+1; j<closeToMid.size() && j<=7; j++)
				if((newDistance=computeDistance(closeToMid[i], closeToMid[j])) < closestDistance)
				{
					closestDistance = newDistance;
					closestPair = pair<Point, Point>(closeToMid[i], closeToMid[j]);
				}
	}
	return closestPair;
}


pair<Point, Point> ClosestPair::getClosestPair(const vector<Point>& pointList) const
{
	//init
	vector<Point> pList;
	pList.assign(pointList.begin(), pointList.end());
	sort(pList.begin(), pList.end(), Point2D<>::less_X);

	return getClosestPair(pList, pList.begin(), pList.end());
}

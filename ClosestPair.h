#ifndef CLOSESTPAIR_H_
#define CLOSESTPAIR_H_

#include <vector>
#include <utility>
#include "Point2D.h"

using BGM::TYPE::Point2D;

typedef Point2D<> Point;

class ClosestPair {
private:
	//std::pair<Point, Point> getClosestPair(const std::vector<Point>& pointList, unsigned int beg, unsigned int end) const;
	std::pair<Point, Point> getClosestPair(const std::vector<Point>& pointList, std::vector<Point>::iterator beg, std::vector<Point>::iterator end) const;
public:
	std::pair<Point, Point> getClosestPair(const std::vector<Point>& pointList) const;
};

#endif

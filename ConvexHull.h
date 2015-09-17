#ifndef CONVEXHULL_H_
#define CONVEXHULL_H_

#include <list>
#include <vector>
#include <utility>
#include "Point2D.h"

using BGM::TYPE::Point2D;

typedef Point2D<> Point;
typedef std::pair<Point, float> PointAndTheta;

class ConvexHull {
private:
	//float getTheta(const Point& p1, const Point& p2) const;
	//void initThetaList(const std::vector<Point>& srcList, std::vector<PointAndTheta>& thetaList) const;
	void initConvexHull(const std::vector<Point>& pointList, std::list<Point*>& convexHull) const;
	void delNonConvexHullPoint(std::list<Point*>& convexHull) const;
	//int crossProduct(const Point& p1, const Point& p2) const;
	//bool isLeftCurve(const Point& p1, const Point& p2, const Point& p3) const;
	//std::vector<Point*>* makeConvexHullSet(const std::vector<PointAndTheta>& thetaList) const;
public:
	std::list<Point*>* getConVexHull(const std::vector<Point>& pointList) const;
};

#endif

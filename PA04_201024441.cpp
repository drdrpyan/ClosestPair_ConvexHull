#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <ctime>
#include <string.h>

#include "Point2D.h"
#include "ConvexHull.h"
#include "ClosestPair.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::list;
using std::pair;
using BGM::TYPE::Point2D;

int main(int argc, char* argv[])
{
	char *infile, *outfile;
	if(argc == 5)
	{
		if(!strcmp(argv[1], "-in") && !strcmp(argv[3], "-out"))
		{
			infile = argv[2];
			outfile = argv[4];
		}
		else if(!strcmp(argv[1], "-out") && !strcmp(argv[3], "-out"))
		{
			infile = argv[4];
			outfile = argv[2];
		}
	}
	else if((argc==2 && strcmp(argv[1], "-help")) || argc!=2)
	{
		cout << "help : -in [input file] -out [output file]" << endl;
		return 0;
	}

	vector< Point2D<> > pointList;
	clock_t start, end;
	ifstream ifs;
	ofstream ofs;

	//input
	ifs.open(infile, std::ios::in);
	int numOfPoint;
	ifs >> numOfPoint;
	int tempX, tempY;
	for(int i=0; i<numOfPoint; i++)
	{
		ifs >> tempX >> tempY;
		pointList.push_back(Point2D<>(tempX, tempY));
	}

	//output
	ofs.open(outfile, std::ios::out);

	//convex hull
	ConvexHull convexHull;
	start = clock();
	list<Point2D<>*> *ch = convexHull.getConVexHull(pointList);
	end = clock();
	ofs << "convex hull time" << endl;
	ofs << (float)(end-start)/CLOCKS_PER_SEC << endl;
	ofs << "convex hull set" << endl;
	for(list<Point2D<>*>::iterator itr=ch->begin(); itr!=ch->end(); itr++)
		ofs << (*itr)->X() << ' ' << (*itr)->Y() << endl;
	ofs << -1 << endl;

	//clesest pair
	ClosestPair closestPair;
	start = clock();
	pair<Point2D<>, Point2D<> > cp = closestPair.getClosestPair(pointList);
	end = clock();
	ofs << "close pair time" << endl;
	ofs << (float)(end-start)/CLOCKS_PER_SEC << endl;
	ofs << "close pair" << endl;
	ofs << cp.first.X() << ' ' << cp.first.Y() << endl;
	ofs << cp.second.X() << ' ' << cp.second.Y();

	return 0;
}

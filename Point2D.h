#ifndef ___BGM__TYPE__POINT2D__H___
#define ___BGM__TYPE__POINT2D__H___
//===================================================================================//
//======================== BGM -> TYPE -> Point2D ===================================//
//===================================================================================//
namespace BGM
{
namespace TYPE
{


//===================================================================================//
//=========================class declaration=========================================//
//===================================================================================//
template <typename NumType = int>
class Point2D
{
private:
	NumType x;
	NumType y;
public:
	Point2D(const NumType& x=0, const NumType& y=0);
	Point2D(const Point2D& point2d);
	const NumType& X() const;
	const NumType& Y() const;

	Point2D& operator=(const Point2D& point2d);
	bool operator==(const Point2D& point2d) const;
	bool operator!=(const Point2D& point2d) const;
	const Point2D operator-(const Point2D& point2d) const;

	static bool less_X(const Point2D& lhs, const Point2D& rhs);
	static bool less_Y(const Point2D& lhs, const Point2D& rhs);
};

//template <typename NumType = int>

//===================================================================================//
//=========================class definition==========================================//
//===================================================================================//
template <typename NumType>
inline Point2D<NumType>::Point2D(const NumType& x, const NumType& y) : x(x), y(y)
{
}

template <typename NumType>
inline Point2D<NumType>::Point2D(const Point2D<NumType>& point2d) : x(point2d.x), y(point2d.y)
{
}

template <typename NumType>
inline const NumType& Point2D<NumType>::X() const
{
	return x;
}

template <typename NumType>
inline const NumType& Point2D<NumType>::Y() const
{
	return y;
}

template <typename NumType>
inline Point2D<NumType>& Point2D<NumType>::operator=(const Point2D<NumType>& point2d)
{
	x = point2d.x;
	y = point2d.y;
	return *this;
}

template <typename NumType>
inline bool Point2D<NumType>::operator==(const Point2D<NumType>& point2d) const
{
	return (this->x==point2d.x) && (this->y==point2d.y);
}

template <typename NumType>
inline bool Point2D<NumType>::operator!=(const Point2D<NumType>& point2d) const
{
	return !( (*this) == point2d );
}

template <typename NumType>
inline const Point2D<NumType> Point2D<NumType>::operator-(const Point2D<NumType>& point2d) const
{
	return Point2D(this->x - point2d.x, this->y - point2d.y);
}

template <typename NumType>
bool Point2D<NumType>::less_X(const Point2D<NumType>& lhs, const Point2D<NumType>& rhs)
{
	return (lhs.x<rhs.x) ? true : ((lhs.x==rhs.x) ? lhs.y < rhs.y : false);
	return false;
}

template <typename NumType>
bool Point2D<NumType>::less_Y(const Point2D<NumType>& lhs, const Point2D<NumType>& rhs)
{
	return (lhs.y<rhs.y) ? true : ((lhs.y==rhs.y) ? lhs.x < rhs.x : false);
	return false;
}


}
}

#endif

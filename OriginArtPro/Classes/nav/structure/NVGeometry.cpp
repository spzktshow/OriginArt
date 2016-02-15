#include "NVGeometry.h"

US_NS_NV;

/************Ledge************/
Ledge::Ledge(const std::vector<cocos2d::Vec2>& points) :_points(points)
{
	CCASSERT(vaild(), "invaild multi ledge");
}

Ledge::~Ledge()
{

}

const std::vector<cocos2d::Vec2>& Ledge::getPoints() const
{
	return _points;
}

unsigned int Ledge::getLedgeNum() const
{
	return _points.size();
}

bool Ledge::vaild() const
{
	if (_points.size() > 1) return true;
	return false;
}


/**********Line************/
Line::Line(const cocos2d::Vec2&origin, const cocos2d::Vec2&destination)
{
	_a = destination.y - origin.y;
	_b = origin.x - destination.x;
	_c = destination.x * origin.y - origin.x * destination.y;

	_origin = origin;
	_destination = destination;
}

Line::~Line()
{

}

const cocos2d::Vec2& Line::getOrigin() const
{
	return _origin;
}

const cocos2d::Vec2& Line::getDestination() const
{
	return _destination;
}

float Line::getA() const
{
	return _a;
}

float Line::getB() const
{
	return _b;
}

float Line::getC() const
{
	return _c;
}

bool Line::hasCross(const Line& otherLine)
{
	return false;
}

cocos2d::Vec2 Line::getCross(const Line& otherLine)
{
	return cocos2d::Point(0, 0);
}
/**************Circle**********/
Circle::Circle(const cocos2d::Vec2& center, float r)
{
	_center = center;
	_r = r;
}

Circle::~Circle()
{

}

const cocos2d::Vec2& Circle::getCenter() const
{
	return _center;
}

float Circle::getR() const
{
	return _r;
}

/**************Triangle**************/
Triangle::Triangle(const cocos2d::Vec2&a, const cocos2d::Vec2&b, const cocos2d::Vec2&c)
{
	_a = a;
	_b = b;
	_c = c;
}

Triangle::~Triangle()
{

}

const cocos2d::Vec2& Triangle::getA() const
{
	return _a;
}

const cocos2d::Vec2& Triangle::getB() const
{
	return _b;
}

const cocos2d::Vec2& Triangle::getC() const
{
	return _c;
}
/***********Quadrilateral***********/
Quadrilateral::Quadrilateral(const std::vector<cocos2d::Vec2>& points) : Ledge(points)
{

}

Quadrilateral::~Quadrilateral()
{

}

const cocos2d::Vec2& Quadrilateral::getA() const
{
	return _points.at(0);
}

const cocos2d::Vec2& Quadrilateral::getB() const
{
	return _points.at(1);
}

const cocos2d::Vec2& Quadrilateral::getC() const
{
	return _points.at(2);
}

const cocos2d::Vec2& Quadrilateral::getD() const
{
	return _points.at(3);
}

bool Quadrilateral::vaild() const
{
	if (_points.size() >= 4) return true;
	return false;
}
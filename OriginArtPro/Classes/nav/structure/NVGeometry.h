#ifndef __NV_GEOMETRY_H_
#define __NV_GEOMETRY_H_

#include "NavMacro.h"

NS_NV_BEGAN

/***多边形**/
class Ledge
{
public:
	Ledge(const std::vector<cocos2d::Vec2>& points);
	virtual ~Ledge();

	const std::vector<cocos2d::Vec2>& getPoints() const;

	/**获取边数**/
	unsigned int getLedgeNum() const;
	/**有效性检测**/
	virtual bool vaild() const;
protected:
	std::vector<cocos2d::Vec2> _points;
};

//line: ax + by + c = 0;
// a = y2 -y1
// b = x1 - x2
// c = x2 * y1 - x1 * y2
class Line
{
public:
	Line(const cocos2d::Vec2&origin, const cocos2d::Vec2&destination);
	~Line();

	const cocos2d::Vec2& getOrigin() const;
	const cocos2d::Vec2& getDestination() const;

	float getA() const;
	float getB() const;
	float getC() const;

	bool hasCross(const Line& otherLine);
	cocos2d::Vec2 getCross(const Line& otherLine);
protected:
	float _a;
	float _b;
	float _c;

	cocos2d::Vec2 _origin;
	cocos2d::Vec2 _destination;
};

class Circle
{
public:
	Circle(const cocos2d::Vec2& center, float r);
	~Circle();

	const cocos2d::Vec2& getCenter() const;
	float getR() const;
protected:
	cocos2d::Vec2 _center;
	float _r;
};

class Triangle
{
public:
	Triangle(const cocos2d::Vec2&a, const cocos2d::Vec2&b, const cocos2d::Vec2&c);
	~Triangle();

	const cocos2d::Vec2& getA() const;
	const cocos2d::Vec2& getB() const;
	const cocos2d::Vec2& getC() const;
protected:
	cocos2d::Vec2 _a;
	cocos2d::Vec2 _b;
	cocos2d::Vec2 _c;
};

class Quadrilateral : public Ledge
{
public:
	Quadrilateral(const std::vector<cocos2d::Vec2>& points);
	~Quadrilateral();

	const cocos2d::Vec2& getA() const;
	const cocos2d::Vec2& getB() const;
	const cocos2d::Vec2& getC() const;
	const cocos2d::Vec2& getD() const;

	bool vaild() const override;
};

//cocos2d::Rect;

NS_NV_END;

#endif//__NV_GEOMETRY_H_
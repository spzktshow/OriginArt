#include "NVDelaunayAlgorithm.h"
#include "math/CCMathBase.h"
#include <math.h>
US_NS_NV;

/*************DelaunayAlgorithm*****************/
cocos2d::Rect DelaunayAlgorithm::calculateRectByPoints(const cocos2d::Vector<cocos2d::Vec2>&points)
{
	float maxX, maxY, minX, minY;
	bool hasMaxX = false, hasMaxY = false, hasMinX = false, hasMinY = false;
	for (auto p : points)
	{
		if (!hasMaxX)
		{
			maxX = p.x;
			hasMaxX = true;
		}
		else if (p.x > maxX)
		{
			maxX = p.x;
		}
		if (!hasMaxY)
		{
			maxY = p.y;
			hasMaxY = true;
		}
		else if (p.y > maxY)
		{
			maxY = p.y;
		}
		if (!hasMinX)
		{
			minX = p.x;
			hasMinX = true;
		}
		else if (p.x < maxX)
		{
			minX = p.x;
		}
	}
	if (!hasMaxX || !hasMaxY || !hasMinX || !hasMinY) return cocos2d::Rect(0, 0, 0, 0);
	cocos2d::Rect rect(cocos2d::Vec2(minX, minY), cocos2d::Size(maxX - minX, maxY - minY));
	return rect;
}

/*************************DelaunayAlgorithm**************************/
Line DelaunayAlgorithm::calculateVerticalMiddleLine(const cocos2d::Vec2& a, const cocos2d::Vec2& b)
{
	cocos2d::Vec2 middle = a.getMidpoint(b);
	cocos2d::AffineTransform transformMatrix = cocos2d::AffineTransform::IDENTITY;
	float radians = MATH_PIOVER2;
	transformMatrix.a = cos(radians);
	transformMatrix.b = sin(radians);
	transformMatrix.c = -sin(radians);
	transformMatrix.d = cos(radians);
	/***变换的时候移位矩阵坐标***/
	transformMatrix.tx = middle.x;
	transformMatrix.ty = middle.y;
	cocos2d::Vec2 a1 = PointApplyAffineTransform(cocos2d::Vec2(a.x - middle.x, a.y - middle.y), transformMatrix);
	cocos2d::Vec2 b1 = PointApplyAffineTransform(cocos2d::Vec2(b.x - middle.x, b.y - middle.y), transformMatrix);
	Line line(a1, b1);
	return line;
}

Line DelaunayAlgorithm::calculateVerticalMiddleLine(const Line& line)
{
	return calculateVerticalMiddleLine(line.getOrigin(), line.getDestination());
}

/***
公式介绍
数学中常用的重要公式之一！
在直角坐标系内，已知两点A(x1,y1),B(x2,y2);在两点连线上有一点P,设它的坐标为(x,y),且向量AP比向量PB的比值为λ,那么我们说P分有向线段AB的比为λ
且P的坐标为
x=(x1 + λ · x2) / (1 + λ)
y=(y1 + λ · y2) / (1 + λ)
***/
cocos2d::Vec2 DelaunayAlgorithm::calculateCrossPoint(const Line&line1, const Line& line2)
{
	float afactor = line2.getA() / line1.getA();
	float y = (line1.getC() * afactor - line2.getC()) / (line2.getB() - line1.getB() * afactor);
	float x = (0 - (line1.getC() + line1.getB() * y)) / line1.getA();
	return cocos2d::Vec2(x, y);
}
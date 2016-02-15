#ifndef __NAV_DELAUNAY_ALGORITHM_H_
#define __NAV_DELAUNAY_ALGORITHM_H_

#include "NavMacro.h"
#include "NVGeometry.h"

NS_NV_BEGAN

class DelaunayAlgorithm
{
public:
	/*********根据点集创建矩形*********/
	static cocos2d::Rect calculateRectByPoints(const cocos2d::Vector<cocos2d::Vec2>&points);

	/*******计算两点的垂直平分线,该函数直接求出a,b向量绕a,b中点旋转90.0f度的两个向量a',b'*******/
	static Line calculateVerticalMiddleLine(const cocos2d::Vec2& a, const cocos2d::Vec2& b);
	static Line calculateVerticalMiddleLine(const Line& line);

	static cocos2d::Vec2 calculateCrossPoint(const Line&line1, const Line& line2);
};

NS_NV_END;

#endif // !__NAV_DELAUNAY_ALGORITHM_H_

#ifndef __NV_VECTOR_ALGORITHM_H_
#define __NV_VECTOR_ALGORITHM_H_

#include "NavMacro.h"
#include "NVGeometry.h"

NS_NV_BEGAN

class VectorAlgorithm
{
public:
	/***矢量叉积***/
	/**P × Q = x1*y2 - x2*y1**/
	/**P × Q = -(Q × P) and P ×(-Q) = -(P × Q)**/
	static float crossProduct(const cocos2d::Vec2&P, const cocos2d::Vec2&Q);

	/***
	折线段的拐向判断方法可以直接由矢量叉积的性质推出。对于有公共端点的线段p0p1和p1p2，通过计算(p2 - p0) × (p1 - p0)的符号便可以确定折线段的拐向：
	*若(p2 - p0) × (p1 - p0) > 0,则p0p1在p1点拐向右侧后得到p1p2。
	*若(p2 - p0) × (p1 - p0) < 0,则p0p1在p1点拐向左侧后得到p1p2。
	*若(p2 - p0) × (p1 - p0) = 0,则p0、p1、p2三点共线。
	***/
	static float inflectionPoint(const cocos2d::Vec2&p0, const cocos2d::Vec2&p1, const cocos2d::Vec2&p2);

	/*****快速排斥******/
	static bool fastExclusion(const nav::Line&p, const nav::Line&q);

	/**********从一条直线快速*********/
	static cocos2d::Rect getRectByLine(const nav::Line&p);

	/***
	所以判断P1P2跨立Q1Q2的依据是：( P1 - Q1 ) × ( Q2 - Q1 ) * ( Q2 - Q1 ) × ( P2 - Q1 ) >  0。
	同理判断Q1Q2跨立P1P2的依据是：( Q1 - P1 ) × ( P2 - P1 ) * ( P2 - P1 ) × ( Q2 - P1 ) >  0。
	****/
	static bool cross(const nav::Line&p, const nav::Line&q);

	/***两线段互为跨立***/
	static bool eachCross(const nav::Line&P, const nav::Line&Q);
};

NS_NV_END;

#endif // !__NV_VECTOR_ALGORITHM_H_

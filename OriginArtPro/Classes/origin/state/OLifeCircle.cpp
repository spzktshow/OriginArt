#include "OLifeCircle.h"

USING_NS_O;

/*************LifeCircleDefiniation*************/
LifeCircleDefiniation::LifeCircleDefiniation(const std::string& type) :_type(type)
{

}

LifeCircleDefiniation::~LifeCircleDefiniation()
{

}

void LifeCircleDefiniation::setType(const std::string& type)
{
	_type = type;
}

const std::string& LifeCircleDefiniation::getType() const
{
	return _type;
}
#include "OGUnit.h"

USING_NS_OG;

Unit::Unit(const UnitDefiniation * unitDefiniation) :_unitDefiniation(unitDefiniation)
{

}

Unit::~Unit()
{
	_unitDefiniation = nullptr;
}
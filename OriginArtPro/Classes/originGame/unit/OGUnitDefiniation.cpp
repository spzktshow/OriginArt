#include "OGUnitDefiniation.h"

NS_OG_BEGIN

/****************UnitPropertyDefiniation******************/
UnitPropertyDefiniation::UnitPropertyDefiniation()
: _moveSpeed(0.0f)
, _actionSpeed(0.0f)
{

}

UnitPropertyDefiniation::~UnitPropertyDefiniation()
{

}

/***************UnitDefiniation****************/

UnitDefiniation::UnitDefiniation() 
	: _id(0)
	, _statesDefiniation(nullptr)
	, _propertyDefiniation(nullptr)
{

}

UnitDefiniation::~UnitDefiniation()
{

}

NS_OG_END
#include "OGUnitStateDefiniation.h"

USING_NS_OG;

/***************UnitStateDefiniation********************/
UnitStateDefiniation::UnitStateDefiniation(const std::string& type, const origin::ExclusionDefiniation * exclusionDefiniation) : StateComponentDefiniation(type, exclusionDefiniation)
{

}

UnitStateDefiniation::~UnitStateDefiniation()
{

}
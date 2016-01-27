#ifndef __ORIGIN_LIFE_CIRCLE_H_
#define __ORIGIN_LIFE_CIRCLE_H_

#include <string>
#include "OriginMacros.h"

NS_O_BEGIN
/***配置状态的生命周期***/
class LifeCircleDefiniation
{
public:
	LifeCircleDefiniation(const std::string& type);
	virtual ~LifeCircleDefiniation();

	void setType(const std::string& type);
	const std::string& getType() const;

protected:
	std::string _type;
};



NS_O_END;

#endif // !__ORIGIN_LIFE_CIRCLE_H_

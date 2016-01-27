#ifndef __ORIGIN_LIFE_CIRCLE_H_
#define __ORIGIN_LIFE_CIRCLE_H_

#include <string>
#include <vector>
#include "OriginMacros.h"
#include "OLifeCircleTrigger.h"

NS_O_BEGIN
/***����״̬����������***/
class LifeCircleDefiniation
{
public:
	LifeCircleDefiniation(const std::string& type);
	virtual ~LifeCircleDefiniation();

	void setType(const std::string& type);
	const std::string& getType() const;

protected:
	std::string _type;

	std::vector<LifeCircleTriggerDefiniation *> _triggers;
};



NS_O_END;

#endif // !__ORIGIN_LIFE_CIRCLE_H_

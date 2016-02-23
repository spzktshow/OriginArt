#ifndef __ORIGIN_EXCLUSION_H_
#define __ORIGIN_EXCLUSION_H_

#include "OriginMacros.h"

NS_O_BEGIN

class ExclusionDefiniation
{
public:
	static const int DEFAULT_EXCLUSION;
	enum class ExclusionType
	{
		PAUSE = 0,
		RESUME,
	};

	ExclusionDefiniation(ExclusionType type);
	virtual ~ExclusionDefiniation();

	const ExclusionType& getType() const;

	int getDefaultExculsion() const;
protected:
	ExclusionType _type;

	int _defaultExclusion;
};

class ExclusionProtocol
{
public:
	virtual ~ExclusionProtocol();

	virtual int exclusion() = 0;
	virtual int unexclusion() = 0;
	virtual void resetExclusion() = 0;
};

class Exclusion : public ExclusionProtocol
{
public:
	Exclusion(const ExclusionDefiniation * exclusionDefiniation);
	virtual ~Exclusion();

	int exclusion() override;
	int unexclusion() override;
	void resetExclusion() override;

	int getExclusionCount() const;

	ExclusionDefiniation::ExclusionType checkType() const;
protected:
	const ExclusionDefiniation * _exclusionDefiniation;

	int _exclusionCount;
};

NS_O_END;

#endif // !__ORIGIN_EXCLUSION_H_

#ifndef REGION_PROVINCE_MAPPER
#define REGION_PROVINCE_MAPPER

#include "newParser.h"
#include <map>
#include <set>

namespace mappers
{
	class RegionProvinceMapper: commonItems::parser
	{
	public:
		RegionProvinceMapper();
		RegionProvinceMapper(std::istream& theStream);
		bool provinceIsInRegion(int province, const std::string& region) const;
		std::set<int> getProvincesInRegion(const std::string& region) const;

	private:
		void registerKeys();
		std::map<std::string, std::set<int>> theRegions;
	};
}

#endif // REGION_PROVINCE_MAPPER
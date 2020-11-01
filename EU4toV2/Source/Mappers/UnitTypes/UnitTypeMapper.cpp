#include "UnitTypeMapper.h"
#include "ParserHelpers.h"
#include "Log.h"
#include <set>
#include "OSCompatibilityLayer.h"
#include "Configuration.h"


void mappers::UnitTypeMapper::initUnitTypeMapper()
{
	LOG(LogLevel::Info) << "Parsing unit strengths from EU4 installation.";

	auto filenames = commonItems::GetAllFilesInFolder(theConfiguration.getEU4Path() + "/common/units/");
	for (const auto& filename : filenames)
	{
		addUnitFileToRegimentTypeMap(theConfiguration.getEU4Path() + "/common/units", filename);
	}

	for (const auto& modName : theConfiguration.getEU4Mods())
	{
		auto moreFilenames = commonItems::GetAllFilesInFolder(modName + "/common/units/");
		for (const auto& filename : moreFilenames)
		{
			addUnitFileToRegimentTypeMap(modName + "/common/units", filename);
		}
	}
}

void mappers::UnitTypeMapper::loadUnitType(const std::string& unitName, std::istream& theStream)
{
	UnitType unitType(theStream);
	if (unitType.getCategory() == EU4::REGIMENTCATEGORY::transport)
		unitType.setStrength(24);
	unitTypeMap.insert(std::pair(unitName, unitType));
}

void mappers::UnitTypeMapper::addUnitFileToRegimentTypeMap(const std::string& directory, const std::string& filename)
{
	const auto period = filename.find_last_of('.');
	auto name = filename.substr(0, period);

	UnitType unitType(directory + "/" + filename);
	if (unitType.getCategory() == EU4::REGIMENTCATEGORY::num_reg_categories)
	{
		LOG(LogLevel::Warning) << "Unit file for " << name << " at: " << directory << "/" << filename << " has no type!";
		return;
	}

	// patch for transports
	if (unitType.getCategory() == EU4::REGIMENTCATEGORY::transport) unitType.setStrength(24);

	unitTypeMap.insert(std::pair(name, unitType));
}

#include "Culture.h"
#include "ParserHelpers.h"
#include <random>

mappers::Culture::Culture(std::istream& theStream)
{
	registerKeys();
	parseStream(theStream);
	clearRegisteredKeywords();
}

void mappers::Culture::registerKeys()
{
	registerKeyword("primary", [this](const std::string& unused, std::istream& theStream) {
		primaryTag = commonItems::singleString(theStream).getString();
	});
	registerKeyword("graphical_culture", [this](const std::string& unused, std::istream& theStream) {
		graphicalCulture = commonItems::singleString(theStream).getString();
	});
	registerKeyword("male_names", [this](const std::string& unused, std::istream& theStream) {
		maleNames = commonItems::stringList(theStream).getStrings();
	});
	registerKeyword("female_names", [this](const std::string& unused, std::istream& theStream) {
		femaleNames = commonItems::stringList(theStream).getStrings();
	});
	registerKeyword("first_names", [this](const std::string& unused, std::istream& theStream) {
		firstNames = commonItems::stringList(theStream).getStrings();
	});
	registerKeyword("last_names", [this](const std::string& unused, std::istream& theStream) {
		lastNames = commonItems::stringList(theStream).getStrings();
	});
	registerKeyword("dynasty_names", [this](const std::string& unused, std::istream& theStream) {
		dynastyNames = commonItems::stringList(theStream).getStrings();
	});
	registerKeyword("color", [this](const std::string& unused, std::istream& theStream) {
		color = commonItems::Color::Factory{}.getColor(theStream);
	});
	registerKeyword("radicalism", [this](const std::string& unused, std::istream& theStream) {
		radicalism = commonItems::singleInt(theStream).getInt();
	});
	registerRegex(commonItems::catchallRegex, commonItems::ignoreItem);
}

void mappers::Culture::transmogrify()
{
	firstNames = maleNames;
	lastNames = dynastyNames;

	std::random_device randomDevice;
	std::mt19937 engine(randomDevice());
	const std::uniform_int_distribution<> distribution(0, 255);

	const auto r = distribution(engine);
	const auto g = distribution(engine);
	const auto b = distribution(engine);
	color = commonItems::Color(std::array<int, 3>{r, g, b});
	primaryTag.clear();
}

#include "CultureGroups/Culture.h"
#include "gtest/gtest.h"

TEST(Mappers_CultureTests, originalCultureCanBeSet)
{
	std::stringstream input;
	mappers::Culture culture(input);

	ASSERT_TRUE(culture.getOriginalCulture().empty());

	culture.setOriginalCulture("c1");

	ASSERT_EQ("c1", culture.getOriginalCulture());
}

TEST(Mappers_CultureTests, maleNamesCanBeRetrievedAndAdded)
{
	std::stringstream input;
	input << "male_names = { Bob Jon }";
	mappers::Culture culture(input);

	ASSERT_EQ(2, culture.getMaleNames().size());
	ASSERT_EQ("Bob", culture.getMaleNames()[0]);
	ASSERT_EQ("Jon", culture.getMaleNames()[1]);

	const std::vector<std::string> moreNames = {"Dod", "Kro"};

	culture.addMaleNames(moreNames);

	ASSERT_EQ(4, culture.getMaleNames().size());
	ASSERT_EQ("Dod", culture.getMaleNames()[2]);
	ASSERT_EQ("Kro", culture.getMaleNames()[3]);
}

TEST(Mappers_CultureTests, femaleNamesCanBeRetrievedAndAdded)
{
	std::stringstream input;
	input << "female_names = { Bob Jon }";
	mappers::Culture culture(input);

	ASSERT_EQ(2, culture.getFemaleNames().size());
	ASSERT_EQ("Bob", culture.getFemaleNames()[0]);
	ASSERT_EQ("Jon", culture.getFemaleNames()[1]);

	const std::vector<std::string> moreNames = {"Dod", "Kro"};

	culture.addFemaleNames(moreNames);

	ASSERT_EQ(4, culture.getFemaleNames().size());
	ASSERT_EQ("Dod", culture.getFemaleNames()[2]);
	ASSERT_EQ("Kro", culture.getFemaleNames()[3]);
}

TEST(Mappers_CultureTests, dynastyNamesCanBeRetrievedAndAdded)
{
	std::stringstream input;
	input << "dynasty_names = { Bob Jon }";
	mappers::Culture culture(input);

	ASSERT_EQ(2, culture.getDynastyNames().size());
	ASSERT_EQ("Bob", culture.getDynastyNames()[0]);
	ASSERT_EQ("Jon", culture.getDynastyNames()[1]);

	const std::vector<std::string> moreNames = {"Dod", "Kro"};

	culture.addDynastyNames(moreNames);

	ASSERT_EQ(4, culture.getDynastyNames().size());
	ASSERT_EQ("Dod", culture.getDynastyNames()[2]);
	ASSERT_EQ("Kro", culture.getDynastyNames()[3]);
}

TEST(Mappers_CultureTests, firstNamesCanBeLoaded)
{
	std::stringstream input;
	input << "first_names = { Bob Jon }";
	const mappers::Culture culture(input);

	ASSERT_EQ(2, culture.getFirstNames().size());
	ASSERT_EQ("Bob", culture.getFirstNames()[0]);
	ASSERT_EQ("Jon", culture.getFirstNames()[1]);
}

TEST(Mappers_CultureTests, lastNamesCanBeLoaded)
{
	std::stringstream input;
	input << "last_names = { Bob Jon }";
	const mappers::Culture culture(input);

	ASSERT_EQ(2, culture.getLastNames().size());
	ASSERT_EQ("Bob", culture.getLastNames()[0]);
	ASSERT_EQ("Jon", culture.getLastNames()[1]);
}

TEST(Mappers_CultureTests, ColorCanBeLoaded)
{
	std::stringstream input;
	input << "color = { 1 2 3 }";
	const mappers::Culture culture(input);

	ASSERT_EQ("= rgb { 1 2 3 }", culture.getColor()->outputRgb());
}

TEST(Mappers_CultureTests, primaryTagCanBeLoaded)
{
	std::stringstream input;
	input << "primary = TAG";
	const mappers::Culture culture(input);

	ASSERT_EQ("TAG", culture.getPrimaryTag());
}

TEST(Mappers_CultureTests, graphicalCultureCanBeLoaded)
{
	std::stringstream input;
	input << "graphical_culture = afro_gfx";
	const mappers::Culture culture(input);

	ASSERT_EQ("afro_gfx", culture.getGraphicalCulture());
}

TEST(Mappers_CultureTests, neocultureCanBeSetAndChecked)
{
	std::stringstream input;
	mappers::Culture culture(input);

	ASSERT_FALSE(culture.isNeoCulture());

	culture.setNeoCulture(true);

	ASSERT_TRUE(culture.isNeoCulture());
}

TEST(Mappers_CultureTests, neocultureSettingSetsRadicalismTo10)
{
	std::stringstream input;
	input << "radicalism = 5";
	mappers::Culture culture(input);

	ASSERT_FALSE(culture.isNeoCulture());
	ASSERT_EQ(5, culture.getRadicalism());

	culture.setNeoCulture(true);

	ASSERT_TRUE(culture.isNeoCulture());
	ASSERT_EQ(10, culture.getRadicalism());
}

TEST(Mappers_CultureTests, cultureCanBeTransmogrifiedFromEU4ToV2)
{
	std::stringstream input;
	input << "primary = TAG\n";
	input << "male_names = { Bob Jon }\n";
	input << "dynasty_names = { Bobby Johnny }\n";
	mappers::Culture culture(input);

	ASSERT_EQ(2, culture.getMaleNames().size());
	ASSERT_EQ(2, culture.getDynastyNames().size());
	ASSERT_EQ("TAG", culture.getPrimaryTag());

	culture.transmogrify();

	ASSERT_EQ(2, culture.getFirstNames().size());
	ASSERT_EQ("Bob", culture.getFirstNames()[0]);
	ASSERT_EQ("Jon", culture.getFirstNames()[1]);
	ASSERT_EQ(2, culture.getLastNames().size());
	ASSERT_EQ("Bobby", culture.getLastNames()[0]);
	ASSERT_EQ("Johnny", culture.getLastNames()[1]);

	ASSERT_TRUE(culture.getColor());					 // it's been set to something random.
	ASSERT_TRUE(culture.getPrimaryTag().empty()); // It's been cleared.
}

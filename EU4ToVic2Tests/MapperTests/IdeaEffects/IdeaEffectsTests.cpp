#include "IdeaEffects/IdeaEffects.h"
#include "gtest/gtest.h"
#include <sstream>

TEST(Mappers_IdeaEffectsTests, primitivesDefaultToNullopt)
{
	std::stringstream input;
	mappers::IdeaEffects ideaEffects(input);

	ASSERT_FALSE(ideaEffects.getArmy());
	ASSERT_FALSE(ideaEffects.getNavy());
	ASSERT_FALSE(ideaEffects.getCommerce());
	ASSERT_FALSE(ideaEffects.getCulture());
	ASSERT_FALSE(ideaEffects.getIndustry());
	ASSERT_FALSE(ideaEffects.getLiberal());
	ASSERT_FALSE(ideaEffects.getReactionary());
	ASSERT_FALSE(ideaEffects.getOrder());
	ASSERT_FALSE(ideaEffects.getLiberty());
	ASSERT_FALSE(ideaEffects.getEquality());
	ASSERT_FALSE(ideaEffects.getLiteracy());
	ASSERT_FALSE(ideaEffects.getSlavery());
	ASSERT_FALSE(ideaEffects.getUpper_house_composition());
	ASSERT_FALSE(ideaEffects.getVote_franchise());
	ASSERT_FALSE(ideaEffects.getVoting_system());
	ASSERT_FALSE(ideaEffects.getPublic_meetings());
	ASSERT_FALSE(ideaEffects.getPress_rights());
	ASSERT_FALSE(ideaEffects.getTrade_unions());
	ASSERT_FALSE(ideaEffects.getPolitical_parties());
}

TEST(Mappers_IdeaEffectsTests, primitivesCanBeSet)
{
	std::stringstream input;
	input << "army = 6\n";
	input << "navy = 1\n";
	input << "commerce = 1\n";
	input << "culture = 1\n";
	input << "industry = 1\n";
	input << "liberal = 4\n";
	input << "reactionary = 7\n";
	input << "order = 1\n";
	input << "liberty = 1\n";
	input << "equality = 1\n";
	input << "literacy = 7\n";
	input << "slavery = 7\n";
	input << "upper_house_composition = 7\n";
	input << "vote_franchise = 7\n";
	input << "voting_system = 7\n";
	input << "public_meetings = 7\n";
	input << "press_rights = 7\n";
	input << "trade_unions = 7\n";
	input << "political_parties = 7\n";

	mappers::IdeaEffects ideaEffects(input);

	ASSERT_EQ(1, ideaEffects.getArmy());
	ASSERT_EQ(-4, ideaEffects.getNavy());
	ASSERT_EQ(-4, ideaEffects.getCommerce());
	ASSERT_EQ(-4, ideaEffects.getCulture());
	ASSERT_EQ(-4, ideaEffects.getIndustry());
	ASSERT_EQ(-1, ideaEffects.getLiberal());
	ASSERT_EQ(2, ideaEffects.getReactionary());
	ASSERT_EQ(-4, ideaEffects.getOrder());
	ASSERT_EQ(-4, ideaEffects.getLiberty());
	ASSERT_EQ(-4, ideaEffects.getEquality());
	ASSERT_EQ(2, ideaEffects.getLiteracy());
	ASSERT_EQ(2, ideaEffects.getSlavery());
	ASSERT_EQ(2, ideaEffects.getUpper_house_composition());
	ASSERT_EQ(2, ideaEffects.getVote_franchise());
	ASSERT_EQ(2, ideaEffects.getVoting_system());
	ASSERT_EQ(2, ideaEffects.getPublic_meetings());
	ASSERT_EQ(2, ideaEffects.getPress_rights());
	ASSERT_EQ(2, ideaEffects.getTrade_unions());
	ASSERT_EQ(2, ideaEffects.getPolitical_parties());
}

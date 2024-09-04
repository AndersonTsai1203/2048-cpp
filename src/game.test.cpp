#include <array>
#include <string>

#include <catch2/catch.hpp>

#include "game.h"

TEST_CASE("basic test") {
	auto start = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "0x2", "0x2", "" },
			{ "",    "",    "" },
			{ "",    "",    "" }
		}
	};

	game::move_0x800(start, game::Move::down);

	auto end = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "",    "",    "" },
			{ "",    "",    "" },
			{ "0x2", "0x2", "" }
		}
	};

	REQUIRE(start == end);
}

TEST_CASE("move right test") {
	auto start = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "0x2", "0x2", "" },
			{ "",    "",    "" },
			{ "",    "",    "" }
		}
	};

	game::move_0x800(start, game::Move::right);

	auto end = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "",    "", "0x4" },
			{ "",    "",    "" },
			{ "",    "",    "" }
		}
	};

	REQUIRE(start == end);
}

TEST_CASE("move up test") {
	auto start = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "",    "",    "" },
			{ "",    "",    "" },
			{ "0x2", "0x2", "" }
		}
	};

	game::move_0x800(start, game::Move::up);

	auto end = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "0x2", "0x2", "" },
			{ "",    "",    "" },
			{ "",    "",    "" }
		}
	};

	REQUIRE(start == end);
}

TEST_CASE("move left test") {
	auto start = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "",    "",    "" },
			{ "",    "",    "" },
			{ "0x2", "0x2", "" }
		}
	};

	game::move_0x800(start, game::Move::left);

	auto end = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "",    "",    "" },
			{ "",    "",    "" },
			{ "0x4", "",    "" }
		}
	};

	REQUIRE(start == end);
}

TEST_CASE("challenge test") {
	auto start = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "",    "",    "0x16" },
			{ "",    "0x4", "" },
			{ "0x2", "0x2", "" }
		}
	};

	game::move_0x800(start, game::Move::left);

	/*auto end = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "0x16",    "",    "" },
			{ "0x4", "",    "" },
			{ "0x4", "",    "" }
		}
	};*/

	game::move_0x800(start, game::Move::up);

	auto end = std::array<std::array<game::cell, 3>, 3>{
		{
			{ "0x16", "",    "" },
			{ "0x8",  "",    "" },
			{ "",     "",    "" }
		}
	};

	REQUIRE(start == end);
}



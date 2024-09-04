#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <array>
#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

namespace game {

	enum class Move { up, down, left, right };
	using cell = std::string;

	auto merge_data (std::string data) -> std::string {
		auto result = std::string{};
		if (data == "0x1") {
			result = "0x2";
		}
		else if (data == "0x1") {
			result = "0x2";
		}
		else if (data == "0x2") {
			result = "0x4";
		}
		else if (data == "0x4") {
			result = "0x8";
		}
		else if (data == "0x8") {
			result = "0x10";
		}
		else if (data == "0x10") {
			result = "0x20";
		}
		else if (data == "0x20") {
			result = "0x40";
		}
		else if (data == "0x40") {
			result = "0x80";
		}
		else if (data == "0x80") {
			result = "0x100";
		}
		else if (data == "0x100") {
			result = "0x200";
		}
		else if (data == "0x200") {
			result = "0x400";
		}
		else if (data == "0x400") {
			result = "0x800";
		}
		return result;
	}

	template <std::size_t size>
	auto print(std::array<std::array<game::cell, size>, size>& grid) -> void {
		for (auto i = size_t{0}; i < grid.size(); ++i) {
				for (auto j = size_t{0}; j < grid[i].size(); ++j) {
					if (grid[i][j] == "") {
						std::cout << "_* "; 
					}
					std::cout << grid[i][j] << " ";
				}
				std::cout << "\n";
		}
	}

	template <std::size_t size>
	void move_0x800(std::array<std::array<game::cell, size>, size>& grid, game::Move direction) {
		if (direction == Move::up) {
			for (auto col = size_t{0}; col < grid.size(); ++col) {
				for (auto row = size_t{0}; row < grid.size(); ++row) {
					if (row + 1 < grid.size()) {
						if (grid[row + 1][col] == "" && grid[row][col] != "") {
							grid[row + 1][col] = grid[row][col];
							grid[row][col] = "";
						}
						else if (grid[row][col] != grid[row + 1][col]) {
							continue;
						}
						else {
							auto new_data = merge_data(grid[row][col]);
							grid[row + 1][col] = new_data;
							grid[row][col] = "";
						}
					}
				}
			}
			auto reversed_grid = std::array<std::array<game::cell, size>, size>{};
			for (auto col = size_t{0}; col < grid.size(); ++col) {
				for (auto row = size_t{0}; row < grid.size(); ++row) {
					reversed_grid[row][col] = grid[grid.size() - row - 1][col];
				}
			}
			grid = reversed_grid;
		}
		else if (direction == Move::down) {
			for (auto col = size_t{0}; col < grid.size(); ++col) {
				for (auto row = size_t{0}; row < grid.size(); ++row) {
					if (row + 1 < grid.size()) {
						if (grid[row + 1][col] == "" && grid[row][col] != "") {
							grid[row + 1][col] = grid[row][col];
							grid[row][col] = "";
						}
						else if (grid[row][col] != grid[row + 1][col]) {
							continue;
						}
						else {
							auto new_data = merge_data(grid[row][col]);
							grid[row + 1][col] = new_data;
							grid[row][col] = "";
						}
					}
				}
			}
			print(grid);
		}
		else if (direction == Move::left) {
			for (auto row = size_t{0}; row < grid.size(); ++row) {
				for (auto col = size_t{0}; col < grid.size(); ++col) {
					if (col + 1 < grid.size()) {
						if (grid[row][col + 1] == "" && grid[row][col] != "") {
							grid[row][col + 1] = grid[row][col];
							grid[row][col] = "";
						}
						else if (grid[row][col] != grid[row][col + 1]) {
							continue;
						}
						else {
							auto new_data = merge_data(grid[row][col]);
							grid[row][col + 1] = new_data;
							grid[row][col] = "";
						}
					}
				}
			}
			auto reversed_grid = std::array<std::array<game::cell, size>, size>{};
			for (auto row = size_t{0}; row < grid.size(); ++row) {
				for (auto col = size_t{0}; col < grid.size(); ++col) {
					reversed_grid[row][col] = grid[row][grid.size() - col - 1];
				}
			}
			grid = reversed_grid;
		}
		else if (direction == Move::right) {
			for (auto row = size_t{0}; row < grid.size(); ++row) {
				for (auto col = size_t{0}; col < grid.size(); ++col) {
					if (col + 1 < grid.size()) {
						if (grid[row][col + 1] == "" && grid[row][col] != "") {
							grid[row][col + 1] = grid[row][col];
							grid[row][col] = "";
						}
						else if (grid[row][col] != grid[row][col + 1]) {
							continue;
						}
						else {
							auto new_data = merge_data(grid[row][col]);
							grid[row][col + 1] = new_data;
							grid[row][col] = "";
						}
					}
				}
			}
		}
	}

} // namespace game

#endif

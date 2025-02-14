#ifndef all_cards__hpp
#define all_cards__hpp

#include <string>
#include <array>
#include "Card.hpp"

template <size_t N>
bool isInArray(int value, const std::array<int, N>& arr) {
  return std::find(arr.begin(), arr.end(), value) != arr.end();
}

std::array<Card*, 122> Cards_Creation();

#endif

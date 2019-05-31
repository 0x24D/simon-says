#include <chrono>
#include <deque>
#include <iostream>
#include <random>
#include <thread>

#define BLUE 0
#define GREEN 1
#define RED 2
#define YELLOW 3

char getColour(const int &num) {
  switch (num) {
  case BLUE:
    return 'B';
  case GREEN:
    return 'G';
  case RED:
    return 'R';
  case YELLOW:
    return 'Y';
  default:
    return '\0';
  }
}

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 3);
  bool endGame = false;
  int score = 0;
  std::deque<char> colours;
  do {
    colours.emplace_back(getColour(dis(gen)));
    std::cout << "Colour sequence:";
    for (char c : colours) {
      std::cout << c;
    }
    std:: cout << "\nEnter colour sequence: ";
    for (char c : colours) {
      char user;
      std::cin >> user;
      if (toupper(user) != c) {
        endGame = true;
        break;
      }
    }
    if (endGame) {
      std::cout << "Incorrect sequence! Ending game. Final score: " << score << '\n';
    } else {
      ++score;
      std::cout << "Correct sequence! Starting level " << (score + 1) << '\n';
    }
  } while (!endGame);
  return 0;
}

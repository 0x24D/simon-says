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
  }
}

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 3);
  bool endGame = false;
  std::deque<char> colours;
  do {
    colours.emplace_back(getColour(dis(gen)));
    std::cout << "Colour sequence:";
    for (char c : colours) {
      std::cout << c;
      // need to sleep and print carriage return to overwrite char
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
      std::cout << "Incorrect sequence! Ending game.\n";
    } else {
      std::cout << "Correct sequence! Next level starting.\n";
    }
  } while (!endGame);
  return 0;
}

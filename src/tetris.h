#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "board.h"
#include "piece.h"

class Tetris
{
public:
	Tetris();
	void run();

private:
	void process_events();
	void update();
	void render();

	void spawn_piece();
	void reset();

private:
	sf::RenderWindow window;
	std::array<Piece, 7> pieces;
	Board board;
	Piece piece;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> dist;
};
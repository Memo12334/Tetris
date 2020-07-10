#include "tetris.h"

Tetris::Tetris()
	:
	window(sf::VideoMode(330, 580), "Tetris"),
	rng(rd()),
	dist(0,6)
{
	reset();
	spawn_piece();
}

void Tetris::run()
{
	window.setFramerateLimit(15);
	while (window.isOpen())
	{
		process_events();
		update();
		render();
	}
}

void Tetris::process_events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Right)
			{
				piece.loc.x++;
				if (board.collides(piece))
					piece.loc.x--;
			}

			else if (event.key.code == sf::Keyboard::Left)
			{
				piece.loc.x--;
				if (board.collides(piece))
					piece.loc.x++;
			}

			else if (event.key.code == sf::Keyboard::Down)
			{
				piece.loc.y++;
				if (board.collides(piece))
				{
					piece.loc.y--;
					reset();
					board.add_piece(piece);
					spawn_piece();
				}
			}
		}
	}
}

void Tetris::update()
{

}


void Tetris::render()
{
	window.clear();
	board.add_piece(piece);
	window.draw(board);
	window.display();
	board.remove_piece(piece);
}

void Tetris::spawn_piece()
{
	piece = pieces[dist(rng)];
}

void Tetris::reset()
{
	pieces[0] = { { {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::CYAN, 0 };
	pieces[1] = { { {{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::BLUE, 0 };
	pieces[2] = { { {{0,0,0,1},{0,1,1,1},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::ORANGE, 0 };
	pieces[3] = { { {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::YELLOW, 0 };
	pieces[4] = { { {{0,0,1,1},{0,1,1,0},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::GREEN, 0 };
	pieces[5] = { { {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::PURPLE, 0 };
	pieces[6] = { { {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}} }, sf::Vector2i(5,0), PieceColor::RED, 0 };
}
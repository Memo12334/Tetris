#include "board.h"

Board::Board()
{
	cell_color[PieceColor::EMPTY]  =	sf::Color::Black;
	cell_color[PieceColor::CYAN]   =	sf::Color::Cyan;
	cell_color[PieceColor::BLUE]   =	sf::Color::Blue;
	cell_color[PieceColor::ORANGE] =	{ 255, 165, 0 };
	cell_color[PieceColor::YELLOW] =    sf::Color::Yellow;
	cell_color[PieceColor::GREEN]  =	sf::Color::Green;
	cell_color[PieceColor::PURPLE] =    { 128, 0, 128 };
	cell_color[PieceColor::RED]    =	sf::Color::Red;
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rect(sf::Vector2f(cell_size, cell_size));
	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(-1.f);

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			rect.setFillColor(cell_color[grid[x][y]]);
			rect.setPosition(x * cell_size, y * cell_size);
			target.draw(rect, states);
		}
	}
}

void Board::add_piece(const Piece& piece)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (piece.shape[y][x])
				grid[piece.loc.x + x][piece.loc.y + y] = piece.color;
		}
	}
}

void Board::remove_piece(const Piece& piece)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (piece.shape[y][x])
				grid[piece.loc.x + x][piece.loc.y + y] = PieceColor::EMPTY;
		}
	}
}

bool Board::collides(const Piece& piece)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (piece.shape[i][j] != 0)
			{
				int y = piece.loc.y + i;
				int x = piece.loc.x + j;
				if (y < 0) return true;
				if (y >= rows) return true;
				if (x < 0) return true;
				if (x >= columns) return true;

				// collision with existing pieces
				if (grid[x][y] != PieceColor::EMPTY)
					return true;
			}
		}
	}
	return false;
}







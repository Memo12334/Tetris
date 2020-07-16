#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "piece.h"

class Board : public sf::Drawable
{
public:
	Board();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void add_piece(const Piece& piece);
	void remove_piece(const Piece& piece);
	bool collides(const Piece& piece) const;
	sf::Vector2i rotate(const sf::Vector2i& piece_coord, const sf::Vector2f& center, const int rotation) const;
	sf::Vector2i piece_coord_to_board_coord(const sf::Vector2i& piece_coord, const Piece& piece) const;

	inline int get_height()
	{
		return rows;
	}
	inline int get_width()
	{
		return columns;
	}

private:
	static constexpr int rows = 22;
	static constexpr int columns = 12;
	static constexpr int cell_size = 25;

	PieceColor grid[columns][rows] = {};
	std::array<sf::Color, 8> cell_color;
};
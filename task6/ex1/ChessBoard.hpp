//
// Created by Aleksander Olsvik on 05.10.2023.
//

#ifndef TASK6_CHESSBOARD_HPP
#define TASK6_CHESSBOARD_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cctype>
#include <math.h>
#include <functional>
#include "ChessBoardPrint.hpp"

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color_, int x_, int y_) : color(color_) {}
        virtual ~Piece() {}
        Color color;

        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        virtual std::string get_text_rep() const = 0;

        /// Move the x/y coordinates of a piece
    };

    class King : public Piece {
    public:
        Color color;
        std::string piece_type;
        King(Color color_, int x_, int y_) : Piece(color_, x_, y_){
            piece_type = "king";
        }

        std::string type() const override {
            return color_string() + " " + piece_type;
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if(abs(from_x-to_x) > 1 || abs(from_y-to_y) > 1) return false;
            else if(to_y < 0 || to_y > 8 || to_x < 0 || to_x > 8) return false;
            else return true;
        }

        std::string get_text_rep() const override {
            return std::string(1, color_string()[0]) + std::string(1, ::toupper(piece_type[0]));
        }


    };

    class Knight : public Piece {
    public:
        Color color;
        std::string piece_type;
        Knight(Color color, int x_, int y_) : Piece(color, x_, y_){
            piece_type = "knight";
        }

        std::string type() const override {
            return color_string() + " " + piece_type;
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if(to_y < 0 || to_y > 8 || to_x < 0 || to_x > 8) return false;
            else if(abs(from_x-to_x) == 2 && abs(to_y-from_y) == 1) return true;
            else if (abs(from_y-to_y) == 2 && abs(to_x-from_x) == 1) return true;
            else return false;
        }

        std::string get_text_rep() const override {
            return std::string(1, color_string()[0]) + std::string(1, (piece_type[0]));
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    std::vector<std::vector<std::unique_ptr<Piece>>> squares;

    std::function<void(const Piece &piece, const std::string &from, const std::string &to)> on_piece_move;
    std::function<void(const Piece &piece, const std::string &square)> on_piece_removed;
    std::function<void(Color color)> on_lost_game;
    std::function<void(const Piece &piece, const std::string &from, const std::string &to)> on_piece_move_invalid;
    std::function<void(const std::string &square)> on_piece_move_missing;
    std::function<void()> after_piece_move;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    /// Move a chess piece if it is a valid move
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(std::string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(std::string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                if (on_piece_move) {
                    on_piece_move(*piece_from, from, to);
                }
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (on_piece_removed)
                            on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (on_lost_game)
                                on_lost_game(king->color);
                        }
                    } else {
                        if (on_piece_move_invalid)
                            on_piece_move_invalid(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = std::move(piece_from);
                after_piece_move();
                return true;
            } else {
                if (on_piece_move_invalid)
                    on_piece_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            if (on_piece_move_missing)
                on_piece_move_missing(from);
            return false;
        }
    }
};


#endif //TASK6_CHESSBOARD_HPP

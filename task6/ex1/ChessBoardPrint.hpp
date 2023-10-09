//
// Created by Aleksander Olsvik on 05.10.2023.
//

#ifndef TASK6_CHESSBOARDPRINT_H
#define TASK6_CHESSBOARDPRINT_H

#include "ChessBoard.hpp"

class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &board) {
        board.on_piece_move = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
            std::cout << piece.type() << " is moving from " << from << " to " << to << std::endl;
        };
        board.on_piece_removed = [](const ChessBoard::Piece &piece, const std::string &square) {
            std::cout << piece.type() << " is being removed from " << square << std::endl;
        };
        board.on_lost_game = [](ChessBoard::Color color) {
            if (color == ChessBoard::Color::WHITE)
                std::cout << "Black";
            else
                std::cout << "White";
            std::cout << " won the game" << std::endl;
        };
        board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
            std::cout << "can not move " << piece.type() << " from " << from << " to " << to << std::endl;
        };
        board.on_piece_move_missing = [](const std::string &square) {
            std::cout << "no piece at " << square << std::endl;
        };
        board.after_piece_move = [this, &board]() {
            print_board(board);
        };
    };

    void print_board(ChessBoard &board) {
        char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        for(char col : charArray) {
            std::cout << " " << col << "  ";
        }
        std::cout << std::endl;
        for (int i = 0; i <= 16; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < 32; j++) {
                    std::cout << "-";
                }
                std::cout << std::endl;
            } else {
                for (int j = 0; j <= 16; j++) {
                    if (j % 2 == 0) {
                        if(j==16) std::cout << "| " << floor(i/2) + 1;
                        else std::cout << "|";
                    }
                    else if (j % 2 == 1) {
                        auto &piece = board.squares[floor(j / 2)][floor(i / 2)];
                        if (piece) {
                            std::cout << piece->get_text_rep() << " ";
                        } else std::cout << "   ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
};

#endif //TASK6_CHESSBOARDPRINT_H
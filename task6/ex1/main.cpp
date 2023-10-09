#include <iostream>
#include <memory>
#include "ChessBoardPrint.hpp"
#include "ChessBoard.hpp"

using namespace std;

int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE, 4, 0);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE, 4, 0);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE, 6, 0);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK, 4, 7);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK, 1 , 7);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK, 6, 7);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}
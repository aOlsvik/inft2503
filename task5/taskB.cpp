#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cctype>
#include <math.h>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color_, int x_, int y_) : color(color_), x(x_), y(y_) {}
        virtual ~Piece() {}

        int x;
        int y;
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

        /// Move the x/y coordinates of a piece
        void move(int to_x, int to_y) {
            x = to_x;
            y = to_y;
        }

        virtual string get_text_rep() const = 0;
    };

    class King : public Piece {
    public:
        Color color;
        string piece_type;
        King(Color color, int x_, int y_) : Piece(color, x, y){
            piece_type = "king";
        }

        string type() const override {
            return color_string() + " " + piece_type;
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if(abs(from_x-to_x) > 1 || abs(from_y-to_y) > 1) return false;
            else if(to_y < 0 || to_y > 8 || to_x < 0 || to_x > 8) return false;
            else return true;
        }

        string get_text_rep() const override {
            return string(1, color_string()[0]) + string(1, ::toupper(piece_type[0]));
        }


    };

    class Knight : public Piece {
    public:
        Color color;
        string piece_type;
        Knight(Color color, int x_, int y_) : Piece(color, x_, y_){
            piece_type = "knight";
        }

        string type() const override {
            return color_string() + " " + piece_type;
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if(to_y < 0 || to_y > 8 || to_x < 0 || to_x > 8) return false;
            else if(abs(from_x-to_x) == 2 && abs(to_y-from_y) == 1) return true;
            else if (abs(from_y-to_y) == 2 && abs(to_x-from_x) == 1) return true;
            else return false;
        }

        string get_text_rep() const override {
            return string(1, color_string()[0]) + string(1, (piece_type[0]));
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                piece_from->move(to_x, to_y);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                print_board();
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }

    void print_board() {
        for(int i = 0; i <= 16; i++){
            if(i%2 == 0){
                for(int j = 0; j<32; j++) {
                    cout << "-";
                }
                cout << endl;
            }
            else {
                for(int j = 0; j<= 16; j++) {
                    if(j % 2 == 0) cout << "|";
                    else if (j % 2 == 1){
                      auto &piece = squares[floor(j/2)][floor(i/2)];
                      if(piece) {
                          cout << piece->get_text_rep() << " ";
                      }
                      else cout << "   ";
                    }
                }
                cout << endl;
            }
        }
    }
};

int main() {
    ChessBoard board;

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
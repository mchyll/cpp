#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
                       BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
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

        // Returns a character representing this piece
        virtual string symbol() const = 0;
    };

    class King : public Piece {
    public:
        King(Color color) : Piece(color) {}
        ~King() {}

        string type() const override {
            return color_string() + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return abs(from_x - to_x) <= 1 && abs(from_y - to_y) <= 1;
        }

        string symbol() const override {
            if (color == Color::WHITE) {
                return "♔";
            } else {
                return "♚";
            }
        }
    };

    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color) {}
        ~Knight() {}

        string type() const override {
            return color_string() + " knight";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            int d_x = abs(from_x - to_x);
            int d_y = abs(from_y - to_y);
            return (d_x == 2 && d_y == 1) || (d_x == 1 && d_y == 2);
        }

        string symbol() const override {
            if (color == Color::WHITE) {
                return "♘";
            } else {
                return "♞";
            }
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

    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;

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

    void print_board() const {
        for (int y = 7; y >= 0; --y) {
            cout << (y + 1) << " ";
            for (int x = 0; x < 8; ++x) {
                if (auto &piece = squares[x][y]) {
                    cout << piece->symbol() << " ";
                } else {
                    if ((y + x) % 2 == 0) {
                        cout << "▓▓";
                    } else {
                        cout << "░░";
                    }
                }
            }
            cout << endl;
        }
        cout << "  a b c d e f g h\n\n";
    }
};

class ChessBoardPrint {
private:
    ChessBoard& board;

public:
    ChessBoardPrint(ChessBoard& _board) : board(_board) {

    }

    void print_board() const {
        for (int y = 7; y >= 0; --y) {
            cout << (y + 1) << " ";
            for (int x = 0; x < 8; ++x) {
                if (auto &piece = board.squares[x][y]) {
                    cout << piece->symbol() << " ";
                } else {
                    if ((y + x) % 2 == 0) {
                        cout << "▓▓";
                    } else {
                        cout << "░░";
                    }
                }
            }
            cout << endl;
        }
        cout << "  a b c d e f g h\n\n";
    }
};

int main() {

    // Oppgave 1:
    // Implementert King og Knight med metodene type og valid_move.

    // Oppgave 2:
    // Implementert metoden print_board i ChessBoard.
    // Utvidet Piece, King og Knigt med metoden symbol.
    // print_board kalles etter hvert gyldige trekk.

    ChessBoard board;

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    cout << "Initial board:" << endl;
    board.print_board();
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

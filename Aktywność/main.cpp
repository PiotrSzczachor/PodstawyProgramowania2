#include <iostream>

using namespace std;

class Board{

public:

    char** board = new char*[3];

    void make_board() const
    {
        for (int i = 0; i < 3; i++)
            board[i] = new char[3];
    }

    void drawing() const
    {
        //Drawing board
        printf("   -------------\n");
        for(int i=0, row=1; i<3; i++, row++)
        {
            printf("%d  ", row);
            for(int j=0; j<3; j++)
            {
                printf("| %c ", board[i][j]);
            }

            printf("|");
            printf("\n");
            printf("   -------------\n");
        }
        printf("\n   ");
        for(int column=1; column<=3; column++)
        {
            printf("  %d ", column);
        }
        printf("\n");
    }

    bool win_check(){
        bool win = false;
        while(!win)
        {
            if(((board[0][0]=='x')&&(board[0][1]=='x')&&(board[0][2]=='x'))
               ||((board[0][0]=='x')&&(board[1][0]=='x')&&(board[2][0]=='x'))
               ||((board[0][0]=='x')&&(board[0][1]=='x')&&(board[0][2]=='x'))
               ||((board[1][0]=='x')&&(board[1][1]=='x')&&(board[1][2]=='x'))
               ||((board[2][0]=='x')&&(board[2][1]=='x')&&(board[2][2]=='x'))
               ||((board[0][1]=='x')&&(board[1][1]=='x')&&(board[2][1]=='x'))
               ||((board[0][2]=='x')&&(board[1][2]=='x')&&(board[2][2]=='x')))
            {
                return true;
            }
            if(((board[0][0]=='o')&&(board[0][1]=='o')&&(board[0][2]=='o'))
               ||((board[0][0]=='o')&&(board[1][0]=='o')&&(board[2][0]=='o'))
               ||((board[0][0]=='o')&&(board[0][1]=='o')&&(board[0][2]=='o'))
               ||((board[1][0]=='o')&&(board[1][1]=='o')&&(board[1][2]=='o'))
               ||((board[2][0]=='o')&&(board[2][1]=='o')&&(board[2][2]=='o'))
               ||((board[0][1]=='o')&&(board[1][1]=='o')&&(board[2][1]=='o'))
               ||((board[0][2]=='o')&&(board[1][2]=='o')&&(board[2][2]=='o')))
            {
                return true;
            }
            return false;
        }
        return 0;
    }

    void fill_board()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                board[i][j] = '-';
            }
        }
    }
};

class Figure{

public:
    char circle;
    char cross;

    void set_circle(){
        circle = 'o';
    }

    void set_cross(){
        cross = 'x';
    }

    void move(char** board, int who)
    {
        int row;
        int col;
        cout<<"Podaj rzad na ktory chcesz sie poruszyc\n";
        cin>>row;
        cout<<"Podaj kolumne na ktora chcesz sie poruszyc\n";
        cin>>col;
        if(who % 2 == 0) {
            board[row - 1][col - 1] = cross;
        } else {
            board[row - 1][col - 1] = circle;
        }


    }

};

int main() {

    int who = 0;
    Figure figure;
    Board board;
    board.make_board();
    board.fill_board();
    board.drawing();
    figure.set_circle();
    figure.set_cross();
    while (!board.win_check())
    {
        figure.move(board.board, who);
        board.drawing();
        who++;
    }




}

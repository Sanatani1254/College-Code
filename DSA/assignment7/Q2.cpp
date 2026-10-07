#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/*There is a single row of colored balls on a board, where each ball can be colored red ’R’, yellow ’Y’, blue ’B’, green ’G’, or white ’W’. You also have several colored balls in your hand. Your goal is to clear all of the balls from the board. On each turn: • Pick any ball from your hand and insert it in between two balls in the row or on either end of the row. • If there is a group of three or more consecutive balls of the same color, remove the group of balls from the board.– If this removal causes more groups of three or more of the same color to form, then continue removing each group until there are none left. • If there are no more balls on the board, then you win the game. • Repeat this process until you either win or do not have any more balls in your hand. Given a std::string board, representing the row of balls on the board, and a std::string hand, representing the balls in your hand, return the minimum number of balls you have to insert to clear all the balls from the board. If you cannot clear all the balls from the board using the balls in your hand, return-1.*/

class game 
{
    private:
    std::unordered_map<std::string, int> a;
    std::string collapse(std::string board) 
    {
        int i = 0;
        while (i<board.length()) {
            int j = i;
            while (j<board.length() && board[j]==board[i]) {j++;}
            if (j-i>=3) return collapse(board.substr(0, i) + board.substr(j));

            i = j;
        }
        return board;
    }

    int search(std::string board, std::string hand) {
        if (board.empty()) return 0;
        if (hand.empty()) return -1;

        std::string state = board + "#" + hand;
        if (a.count(state)) return a[state];
        int minballs = 999; 

        for (int j=0;j<hand.length();j++) 
        {
            if (j > 0 && hand[j]==hand[j-1]) continue;

            for (int i =0;i<=board.length();i++) 
            {
                bool insert = false;
                if (i<board.length()&&board[i]==hand[j]) 
                {
                    insert = true; 
                }
                if (i > 0 && i<board.length() && board[i-1]==board[i] && board[i]!=hand[j]) 
                {
                    insert = true;
                }

                if (insert) 
                {
                    std::string newboard = collapse(board.substr(0,i)+hand[j] + board.substr(i));
                    std::string newhand = hand.substr(0, j) + hand.substr(j + 1);
                    
                    int steps = search(newboard, newhand);
                    if (steps != -1) minballs = std::min(minballs,1+steps);
                    
                }
            }
        }

        a[state] = (minballs == 999 ? -1 : minballs);
        return a[state];
    }

public:
    int findminstep(std::string board, std::string hand) 
    {
        std::sort(hand.begin(), hand.end());
        return search(board, hand);
    }
};

int main() {
    game g;
    
    std::string board = "WWRRBBWW";
    std::string hand = "WRBRW";
    
    int result = g.findminstep(board, hand);
    
    if (result != -1) 
    {
        std::cout << "Min balls to clear board: " <<result<<std::endl;
    } 
    else 
    {
        std::cout<<"Cannot clear board "<<std::endl;
    }
}
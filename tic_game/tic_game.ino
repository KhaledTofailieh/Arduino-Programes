#include"XOGame.h"
class xo_game {
  private:
    char square[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
  public:
    int checkwin()
    {
      if (square[1] == square[2] && square[2] == square[3] && square[3] != '-')
        return 1;

      else if (square[4] == square[5] && square[5] == square[6] && square[6] != '-')
        return 1;

      else if (square[7] == square[8] && square[8] == square[9] && square[9] != '-')
        return 1;

      else if (square[1] == square[4] && square[4] == square[7] && square[7] != '-')
        return 1;

      else if (square[2] == square[5] && square[5] == square[8] && square[8] != '-')
        return 1;

      else if (square[3] == square[6] && square[6] == square[9] && square[9] != '-')
        return 1;

      else if (square[1] == square[5] && square[5] == square[9] && square[9] != '-')
        return 1;

      else if (square[3] == square[5] && square[5] == square[7] && square[7] != '-')
        return 1;

      else if (square[1] != '-' && square[2] != '-' && square[3] != '-' &&
               square[4] != '-' && square[5] != '-' && square[6] != '-' && square[7]
               != '7' && square[8] != '-' && square[9] != '-')

        return 0;
      else
        return  - 1;
    }
    bool is_avaliable_square(int pos) {
      return this->square[pos] == '-';
    }
    void play(char mark, int pos) {
      this->square[pos] = mark;
    }
    char * get_grid() {
      return this->square;
    }
};





void setup() {


}

void loop() {
  // put your main code here, to run repeatedly:

}

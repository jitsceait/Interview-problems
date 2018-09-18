package com.company;

/**
 * Created by sangar on 28.8.18.
 */
public class PlayGame {
    public  static void main (String[] args){
        Game game = new Game(10); //starting with n = 10;
        do{
            game.result(game.compare(game.computerChoice(),game.playerChoice()));
        }while(game.playAgain().equals('n'));
    }
}

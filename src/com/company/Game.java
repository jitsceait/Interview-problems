package com.company;

/**
 * Created by sangar on 27.8.18.
 */
import java.util.Random;
import java.util.Scanner;

public class Game {

    private int computerScore;
    private int playerScore;
    private int numGames;
    private int defaultNumGames;

    public enum Choice {
        ROCK, PAPER, SCISSORS
    }

    public Game(int defaultNumGames){
        this.defaultNumGames = defaultNumGames;
    }

    public Choice playerChoice() {
        Character playerChoice;
        Scanner playerInput = new Scanner(System.in);
        System.out.println("Enter \"r\" for rock, \"p\" for paper, or \"s\" for scissor:");
        playerChoice = playerInput.next().charAt(0);
        switch(playerChoice) {
            case 'r': return Choice.ROCK;
            case 'p' : return Choice.PAPER;
            case 's' : return Choice.SCISSORS;
        }
        return playerChoice();
    }

    public Choice computerChoice() {
        Random random = new Random();
        int computerChoice = random.nextInt(3);
        switch (computerChoice) {
            case 0: return Choice.ROCK;
            case 1: return Choice.PAPER;
            case 2: return Choice.SCISSORS;
        }
        return null;
    }

    public int compare(Choice player, Choice computer) {
        if (player.equals(computer)) return 0;
        switch (player) {
            case ROCK: return(computer == Choice.SCISSORS ? 1 : -1);
            case SCISSORS: return(computer == Choice.PAPER ? 1 : -1);
            case PAPER: return(computer == Choice.ROCK ? 1 : -1);
        }
        return 0;
    }

    public void result(int result) {
        switch (result) {
            case -1:
                System.out.println("Sorry, you lose.");
                computerScore++;
                break;
            case 0:
                System.out.println("Tie!");
                break;
            case 1:
                System.out.println("You win!");
                playerScore++;
                break;
        }
        numGames++;
    }

    public Character playAgain() {
        Scanner scan = new Scanner(System.in);
        Character playAgain;
        do {
            //This is for minimum n games to be played condition
            if(numGames < defaultNumGames){
                System.out.println("You have to play " + (defaultNumGames-numGames) + " games before you can exit");
                return 'y';
            }
            System.out.println("Play again (y/n)?");
            playAgain = scan.next().charAt(0);
        } while(!playAgain.equals('y') && !playAgain.equals('n'));
        return playAgain;
    }
}
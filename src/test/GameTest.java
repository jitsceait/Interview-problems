package test;

import com.company.Game;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

/**
 * Created by sangar on 28.8.18.
 */
public class GameTest {

    Game tester = new Game(10);
    @Test
    public void HumanPlayerWins() {
        assertEquals(1, tester.compare(Game.Choice.PAPER, Game.Choice.ROCK), "Paper beats rock");
        assertEquals(1, tester.compare(Game.Choice.ROCK, Game.Choice.SCISSORS), "Rock beats scissors");
        assertEquals(1, tester.compare(Game.Choice.SCISSORS, Game.Choice.PAPER), "Scissors beats paper");
    }

    @Test
    public void ComputerPlayerWins() {
        assertEquals(-1, tester.compare(Game.Choice.ROCK, Game.Choice.PAPER), "Paper beats rock");
        assertEquals(-1, tester.compare(Game.Choice.SCISSORS, Game.Choice.ROCK), "Rock beats scissors");
        assertEquals(-1, tester.compare(Game.Choice.PAPER, Game.Choice.SCISSORS), "Scissors beats paper");
    }
}

#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>
#include "Game.h"
#include "test_utilities.h"

using std::cout;
using std::endl;
using std::ofstream;

Game InputTest() {
    cout << "cheak input Test" << endl;
    Game game(6);
    (game.addPlayer("itai", "lazer gun", LEVEL, 5) == SUCCESS) ? cout
            << "pass test 1" << endl : cout << "failed test 1" << endl;
    (game.addPlayer("sean", "light saver", LIFE, 6) == SUCCESS) ? cout
            << "pass test 2" << endl : cout << "failed test 2" << endl;
    (game.addPlayer("liad", "pirate sword", STRENGTH, 7) == SUCCESS) ? cout
            << "pass test 3" << endl : cout << "failed test 3" << endl;
    (game.addPlayer("ari", "lazer gun", LEVEL, 5) == SUCCESS) ? cout
            << "pass test 4" << endl : cout << "failed test 4" << endl;
    (game.addPlayer("sean", "TNT", LEVEL, 5) == NAME_ALREADY_EXISTS) ? cout
            << "pass test 5" << endl : cout << "failed test 5" << endl;
    (game.addPlayer("ari", "TNT", LEVEL, 5) == NAME_ALREADY_EXISTS) ? cout
            << "pass test 6" << endl : cout << "failed test 6" << endl;
    (game.addPlayer("yuval", "ATOM", LEVEL, 10) == SUCCESS) ? cout
            << "pass test 7" << endl : cout << "failed test 7" << endl;
    (game.addPlayer("yuval", "ATOM", LEVEL, 10) == NAME_ALREADY_EXISTS) ? cout
            << "pass test 8" << endl : cout << "failed test 8" << endl;
    (game.addPlayer("seana", "ATOM", LIFE, 10) == SUCCESS) ? cout
            << "pass test 9" << endl : cout << "failed test 9" << endl;
    (game.addPlayer("orr", "ATOM", LIFE, 100) == GAME_FULL) ? cout
            << "pass test 10" << endl : cout << "failed test 10" << endl;
    (game.addPlayer("sean", "ATOM", LIFE, 100) == GAME_FULL) ? cout
            << "pass test 11" << endl : cout << "failed test 11" << endl;
    return game;
}

void nextLevelTest(Game &game) {
    cout << "cheak nextLevelTest" << endl;
    (game.nextLevel("ari") == SUCCESS) ? cout << "pass test 1" << endl : cout
            << "failed test 1" << endl;
    (game.nextLevel("itai") == SUCCESS) ? cout << "pass test 2" << endl : cout
            << "failed test 2" << endl;
    (game.nextLevel("itai") == SUCCESS) ? cout << "pass test 3" << endl : cout
            << "failed test 3" << endl;
    (game.nextLevel("liad") == SUCCESS) ? cout << "pass test 4" << endl : cout
            << "failed test 4" << endl;
    (game.nextLevel("yuval") == SUCCESS) ? cout << "pass test 5" << endl : cout
            << "failed test 5" << endl;
    (game.nextLevel("liad") == SUCCESS) ? cout << "pass test 6" << endl : cout
            << "failed test 6" << endl;
    (game.nextLevel("orr") == NAME_DOES_NOT_EXIST) ? cout << "pass test 7"
                                                          << endl : cout
            << "failed test 7" << endl;
    (game.nextLevel("sean") == SUCCESS) ? cout << "pass test 8" << endl : cout
            << "failed test 8" << endl;
    (game.nextLevel("seana") == SUCCESS) ? cout << "pass test 9" << endl : cout
            << "failed test 9" << endl;
    (game.nextLevel("Yuval") == NAME_DOES_NOT_EXIST) ? cout << "pass test 10"
                                                            << endl : cout
            << "failed test 11" << endl;
}

void makeStepTest(Game &game) {
    cout << "cheak makeStep" << endl;
    (game.makeStep("ari") == SUCCESS) ? cout << "pass test 1" << endl : cout
            << "failed test 1" << endl;
    (game.makeStep("itai") == SUCCESS) ? cout << "pass test 2" << endl : cout
            << "failed test 2" << endl;
    (game.makeStep("itai") == SUCCESS) ? cout << "pass test 3" << endl : cout
            << "failed test 3" << endl;
    (game.makeStep("liad") == SUCCESS) ? cout << "pass test 4" << endl : cout
            << "failed test 4" << endl;
    (game.makeStep("yuval") == SUCCESS) ? cout << "pass test 5" << endl : cout
            << "failed test 5" << endl;
    (game.makeStep("liad") == SUCCESS) ? cout << "pass test 6" << endl : cout
            << "failed test 6" << endl;
    (game.makeStep("orr") == NAME_DOES_NOT_EXIST) ? cout << "pass test 7"
                                                         << endl : cout
            << "failed test 7" << endl;
    (game.makeStep("sean") == SUCCESS) ? cout << "pass test 8" << endl : cout
            << "failed test 8" << endl;
    (game.makeStep("seana") == SUCCESS) ? cout << "pass test 9" << endl : cout
            << "failed test 9" << endl;
    (game.makeStep("Yuval") == NAME_DOES_NOT_EXIST) ? cout << "pass test 10"
                                                           << endl : cout
            << "failed test 10" << endl;
}

void addLife(Game &game) {
    cout << "cheak addLife" << endl;
    (game.addLife("ari") == SUCCESS) ? cout << "pass test 1" << endl : cout
            << "failed test 1" << endl;
    (game.addLife("itai") == SUCCESS) ? cout << "pass test 2" << endl : cout
            << "failed test 2" << endl;
    (game.addLife("itai") == SUCCESS) ? cout << "pass test 3" << endl : cout
            << "failed test 3" << endl;
    (game.addLife("liad") == SUCCESS) ? cout << "pass test 4" << endl : cout
            << "failed test 4" << endl;
    (game.addLife("yuval") == SUCCESS) ? cout << "pass test 5" << endl : cout
            << "failed test 5" << endl;
    (game.addLife("liad") == SUCCESS) ? cout << "pass test 6" << endl : cout
            << "failed test 6" << endl;
    (game.addLife("orr") == NAME_DOES_NOT_EXIST) ? cout << "pass test 7" << endl
                                                 : cout << "failed test 7"
                                                        << endl;
    (game.addLife("sean") == SUCCESS) ? cout << "pass test 8" << endl : cout
            << "failed test 8" << endl;
    (game.addLife("seana") == SUCCESS) ? cout << "pass test 9" << endl : cout
            << "failed test 9" << endl;
    (game.addLife("Yuval") == NAME_DOES_NOT_EXIST) ? cout << "pass test 10"
                                                          << endl : cout
            << "failed test 10" << endl;
}

void addStrength(Game &game) {
    cout << "cheak addStrength " << endl;
    (game.addStrength("ari", 1) == SUCCESS) ? cout << "pass test 1" << endl :
    cout << "failed test 1" << endl;
    (game.addStrength("itai", 1) == SUCCESS) ? cout << "pass test 2" << endl :
    cout << "failed test 2" << endl;
    (game.addStrength("itai", 2) == SUCCESS) ? cout << "pass test 3" << endl :
    cout << "failed test 3" << endl;
    (game.addStrength("liad", -5) == INVALID_PARAM) ? cout << "pass test 4"
                                                           << endl : cout
            << "failed test 4" << endl;
    (game.addStrength("yuval", 0) == SUCCESS) ? cout << "pass test 5" << endl :
    cout << "failed test 5" << endl;
    (game.addStrength("liad", 1) == SUCCESS) ? cout << "pass test 6" << endl :
    cout << "failed test 6" << endl;
    (game.addStrength("orr", 10) == NAME_DOES_NOT_EXIST) ? cout << "pass test 7"
                                                                << endl : cout
            << "failed test 7" << endl;
    (game.addStrength("sean", 2) == SUCCESS) ? cout << "pass test 8" << endl :
    cout << "failed test 8" << endl;
    (game.addStrength("seana", 2) == SUCCESS) ? cout << "pass test 9" << endl :
    cout << "failed test 9" << endl;
    (game.addStrength("Yuval", 3) == NAME_DOES_NOT_EXIST) ? cout
            << "pass test 10" << endl : cout << "failed test 10" << endl;
}

void remove(Game &game, int num) {
    cout << "cheak remove " << endl;
    (!game.removeAllPlayersWithWeakWeapon(0)) ? cout << "pass test 1" << endl :
    cout << "failed test 1" << endl;

    (!game.removeAllPlayersWithWeakWeapon(5)) ? cout << "pass test 2" << endl :
    cout << "failed test 2" << endl;

    (game.removeAllPlayersWithWeakWeapon(15)) ? cout << "pass test 3" << endl :
    cout << "failed test 3" << endl;

}

void inputTest2(Game &game) {
    cout << "cheak input after remove " << endl;
    (game.addPlayer("tomer", "ak47", LIFE, 10) == SUCCESS) ? cout
            << "pass test 1" << endl : cout << "failed test 1" << endl;
    (game.addPlayer("sagiv", "m16", LEVEL, 10) == SUCCESS) ? cout
            << "pass test 2" << endl : cout << "failed test 2" << endl;
    (game.addPlayer("sean", "m16", LEVEL, 10) == NAME_ALREADY_EXISTS) ? cout
            << "pass test 3" << endl : cout << "failed test 3" << endl;
}

void firstFight(Game &game) {

    cout << "cheak fight " << endl;
    (game.fight("tomer", "sean") == FIGHT_FAILED) ? cout << "pass test 1"
                                                         << endl : cout
            << "failed test 1" << endl;
    (game.fight("tomer", "ari") == NAME_DOES_NOT_EXIST) ? cout << "pass test 2"
                                                               << endl : cout
            << "failed test 2" << endl;
    if (game.fight("sagiv", "tomer") == SUCCESS) {
        cout << "pass test 3" << endl;
    } else {
        cout << "failed test 3" << endl;
    }

}

void secondFight(Game &game) {
    GameStatus status;
    status = game.makeStep("tomer");
    assert(status == SUCCESS);
    if (status) cout << "use status" << endl;
    (game.fight("tomer", "seana") == FIGHT_FAILED) ? cout << "pass test 4"
                                                          << endl : cout
            << "failed test 4" << endl;
    for (int i = 0; i < 15; i++) {
        status = game.addLife("sean");
        assert(status == SUCCESS);
    }
    (game.fight("tomer", "sean") == SUCCESS) ? cout << "pass test 5" << endl :
    cout << "failed test 5" << endl;

}

void Test() {
    ofstream outputFile("TestOutPut");

    Game game = InputTest();
    outputFile << "INPUT RESULT" << endl;
    outputFile << game;

    nextLevelTest(game);
    makeStepTest(game);
    addLife(game);
    addStrength(game);


    remove(game, 2);
    outputFile << "REMOVE RESULT" << endl;
    outputFile << game;


    inputTest2(game);
    outputFile << "INPUT AFTER REMOVE RESULT" << endl;
    outputFile << game;

    firstFight(game);
    outputFile << "FIRST FIGHT" << endl;
    outputFile << game;
    secondFight(game);
    outputFile << "SECOND FIGHT" << endl;
    outputFile << game;
    (game.fight("tomer", "sean") == SUCCESS) ? cout << "pass test 6" << endl :
    cout << "failed test 6" << endl;
    (game.fight("tomer", "sean") == NAME_DOES_NOT_EXIST) ? cout << "pass test 7"
                                                                << endl : cout
            << "failed test 7" << endl;
    outputFile << "FINALE FIGHT" << endl;
    outputFile << game;
    cout << "GOOD LUCK ON INFI 2.0" << endl;
}

void simpleTest() {
    Game game = Game(5);
    assert(game.addPlayer("Linoy", "lazer gun", LEVEL, 5) == SUCCESS);
    assert(game.addPlayer("Denis", "light saver", LIFE, 7) == SUCCESS);
    assert(game.addPlayer("Gal", "pirate sword", STRENGTH, 6) == SUCCESS);
    cout << game << endl;
    assert(game.fight("Linoy", "Denis") == SUCCESS);
    cout << game << endl;
    assert(game.addPlayer("Alon", "lazer gun", STRENGTH, 5) == SUCCESS);
    assert(game.addStrength("Alon", 10) == SUCCESS);
    assert(game.fight("Alon", "Gal") == SUCCESS);
    cout << game << endl;
    assert(game.removeAllPlayersWithWeakWeapon(13) == true);
    cout << game << endl;


}

void myTest() {
    cout << "~~~~~~~myTest~~~~~~~~~~" << endl;

}

void GameAddPlayerTest() {
    _print_mode_name("Testing GameAddPlayer function");
    Game game = Game(2);
    test(game.addPlayer("Censor", "integral", LIFE, 3) != SUCCESS,
         "GameAddPlayer doesn't return SUCCESS on successful addition",
         __LINE__);
    test(game.addPlayer("Censor", "integral", LIFE, 3) != NAME_ALREADY_EXISTS,
         "GameAddPlayer doesn't return NAME_ALREADY_EXISTS error",
         __LINE__);
    game.addPlayer("Alex", "derivative", LIFE, 3);
    test(game.addPlayer("Aliza", "Matrix", LIFE, 5) != GAME_FULL,
         "GameAddPlayer doesn't return GAME_FULL on error",
         __LINE__);
}

void GameNextLevelTest() {
    _print_mode_name("Testing GameNextLevel function");
    Game game = Game(1);
    game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
    test(game.nextLevel("Linoy") != SUCCESS,
         "GameNextLevel doesn't return SUCCESS on successful increase of lvl",
         __LINE__);
    test(game.nextLevel("Moshe") != NAME_DOES_NOT_EXIST,
         "GameNextLevel doesn't return NAME_DOES_NOT_EXIST on player which doesn't exists.",
         __LINE__);
}

void GameMakeStepTest() {
    _print_mode_name("Testing GameMakeStep function");
    Game game = Game(1);
    game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
    test(game.makeStep("Linoy") != SUCCESS,
         "GameMakeStep doesn't return SUCCES on successful step.",
         __LINE__);
    test(game.makeStep("Chris") != NAME_DOES_NOT_EXIST,
         "GameMakeStep doesn't return NAME_DOES_NOT_EXISTS on player which doesn't exists.",
         __LINE__);
}

void GameAddLifeTest() {
    _print_mode_name("Testing GameAddLife function");
    Game game = Game(1);
    game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
    test(game.addLife("Linoy") != SUCCESS,
         "GameAddLife doesn't return SUCCESS on successful step.",
         __LINE__);
    test(game.addLife("Chris") != NAME_DOES_NOT_EXIST,
         "GameAddLife doesn't return NAME_DOES_NOT_EXISTS on player which doesn't exists.",
         __LINE__);
}

void GameAddStrengthTest() {
    _print_mode_name("Testing GameAddStrength function");
    Game game = Game(1);
    game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
    test(game.addStrength("Linoy", 5) != SUCCESS,
         "GameAddLife doesn't return SUCCESS on successful step.",
         __LINE__);
    test(game.addStrength("Chris", 5) != NAME_DOES_NOT_EXIST,
         "GameAddStrength doesn't return NAME_DOES_NOT_EXISTS on player which doesn't exists.",
         __LINE__);
    test(game.addStrength("Linoy", -1) != INVALID_PARAM,
         "GameAddStrength doesn't return INVALID_PARAM on negative strength input.",
         __LINE__);
}

void GameRemoveAllPlayersWIthWeakWeaponTest() {
    _print_mode_name("Testing GameRemoveAllPlayersWIthWeakWeapon function");
    Game game = Game(6);
    game.addPlayer("Linoy", "lazer gun", LEVEL, 5);
    game.addPlayer("Nazar", "lazer gun", LEVEL, 7);
    game.addPlayer("Max", "lazer gun", LIFE, 3);
    game.addPlayer("Guy", "lazer gun", STRENGTH, 4);
    game.removeAllPlayersWithWeakWeapon(6);
    test(game.addPlayer("Linoy", "lazer gun", LEVEL, 5) != SUCCESS,
         "GameRemoveAllPlayersWIthWeakWeapon didn't remove the player correctly.",
         __LINE__);
    test(game.addPlayer("Nazar", "lazer gun", LEVEL, 5) != NAME_ALREADY_EXISTS,
         "GameRemoveAllPlayersWIthWeakWeapon removes players with weapon value higher than required.",
         __LINE__);
    test(game.addPlayer("Max", "lazer gun", LEVEL, 5) != NAME_ALREADY_EXISTS,
         "GameRemoveAllPlayersWIthWeakWeapon removes players with weapon value higher than required.",
         __LINE__);
    test(game.addPlayer("Guy", "lazer gun", LEVEL, 5) != NAME_ALREADY_EXISTS,
         "GameRemoveAllPlayersWIthWeakWeapon removes players with weapon value higher than required.",
         __LINE__);
}

void GameFightTest() {
    _print_mode_name("Testing GameFight function");
    Game game = Game(10);
    game.addPlayer("Linoy", "lazer gun", LEVEL, 1);
    game.addPlayer("Terry", "lazer gun", LIFE, 1);
    game.addPlayer("Markus", "lazer gun", STRENGTH, 1);
    game.addPlayer("Kevin", "lazer gun", STRENGTH, 2);
    game.addPlayer("Roi", "lazer gun", LIFE, 2);
    game.addPlayer("Nazar", "lazer gun", LEVEL, 2);
    game.addPlayer("Max", "lazer gun", LIFE, 2);
    game.addPlayer("Guy", "lazer gun", STRENGTH, 2);
    game.makeStep("Markus");
    game.makeStep("Linoy");
    game.makeStep("Nazar");
    game.makeStep("Kevin");
    game.makeStep("Terry");
    game.makeStep("Roi");
    game.makeStep("Max");
    game.makeStep("Max");
    game.fight("Terry", "Roi");
    game.fight("Markus", "Kevin");
    test(game.fight("Linoy", "Nazar") != SUCCESS,
         "GameFight didn't return SUCCESS on valid fight.",
         __LINE__);
    test(game.fight("Linoy", "Nazar") != NAME_DOES_NOT_EXIST,
         "GameFight didn't return NAME_DOES_NOT_EXIST when one of the players is dead(Lvl = 0).",
         __LINE__);
    test(game.addPlayer("Linoy", "lazer gun", LEVEL, 1) != SUCCESS,
         "GameFight didn't remove dead player after fight(Linoy) died due to Level = 0.",
         __LINE__);
    test(game.addPlayer("Terry", "lazer gun", LEVEL, 1) != SUCCESS,
         "GameFight didn't remove dead player after fight(Terry) died due to Life = 0.",
         __LINE__);
    test(game.addPlayer("Markus", "lazer gun", LEVEL, 1) != SUCCESS,
         "GameFight didn't remove dead player after fight(Markus) died due to Strength = 0.",
         __LINE__);
    test(game.fight("Nazar", "Max") != FIGHT_FAILED,
         "GameFight didn't return FIGHT_FAILED when 2 players were in different cells.",
         __LINE__);
    test(game.fight("Player1", "Max") != NAME_DOES_NOT_EXIST,
         "GameFight didn't return NAME_DOES_NOT_EXIST when name of player one isn't an existing player name",
         __LINE__);
    test(game.fight("Max", "Player1") != NAME_DOES_NOT_EXIST,
         "GameFight didn't return NAME_DOES_NOT_EXIST when player two isn't an existing player name.",
         __LINE__);
}

void memoryTestUnit() {
    { // block check if assignment free's memory of weapon a after re-assignment
        Weapon gun = Weapon("gun", LIFE, 5);
        Weapon knife = Weapon("knife", LIFE, 5);
        gun = knife;
        gun = gun; //self assignment check
        Weapon fork = Weapon(knife);
    }
    { // block check if assignment free's memory of player after re-assignment
        Weapon gun = Weapon("gun", LIFE, 5);
        Weapon knife = Weapon("knife", LIFE, 5);
        Player max = Player("Max", gun);
        Player dan = Player("Max", knife);
        Player dave = Player(max);
        max = dan;
        max = max; //self assignment check
    }
    { //self assignment check/cp'ctor
        Game game = Game(1);
        Game game2 = Game(2);
        game2.addPlayer("Linoy", "lazer gun", LEVEL, 1);
        game = game2; //assignment test
        game = game;


    }
}

int main() {
    cout <<
         "\tWelcome to the homework 4 mtmflix tests, "
                 "written by Vova Parakhin.\n\n\t---Passing those tests won't"
                 " guarantee you a good grade---\nBut they might get you closer"
                 ",make some tests yourself to be sure.\n\n";
    cout << "You can change w/e you want in the file itself"
            " but make sure \nto contact me if you want to upload";
    cout << " \'upgraded version\' of the file.\n" << endl;
    cout << "Press ENTER to start the tests:. ";
    getchar();
    GameAddPlayerTest();
    GameNextLevelTest();
    GameMakeStepTest();
    GameAddLifeTest();
    GameAddStrengthTest();
    GameRemoveAllPlayersWIthWeakWeaponTest();
    GameFightTest();
    memoryTestUnit();
    print_grade();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Check!" << std::endl;
    int i(2);
    std::cout << i << std::endl;
    myTest();
    simpleTest();
    Test();

    simpleTest();

    cout << "End of main" << endl;
    return 0;
}
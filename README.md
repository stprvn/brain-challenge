# brain-challenge
Brain Challange is a memorizing game. Project For Algorithm and Data Structure Course

To Compile : gcc brain.c -o <randomname>

The rules of play in this game are the players are required to remember the number of symbols * appearing in a given scene, which each scene allows for the emergence of 15 symbols between +, -, /, *,%, and $ symbols. At the beginning of the game, given 3 scenes each containing 15 symbols, and each new scene, the old scene will be removed from view. Every scene, players are given t seconds to count and remember the number * that appears. 

Simply ,that you will given a number and you just remember 3 first number .After starting with 3 first scenes players will asked how many "*" numbers appear in the Scene(firstScene). If the answer is true the player will be given the next scene , Scene(numberofScene +1) to remember ,and then players will asked again to answer the  numbers of "*" of the Scene(firstScene +1).
There will be 3 stage in this game , easy medium hard , the different is just the t seconds that given.
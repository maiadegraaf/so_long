# so_long
A basic 2D game in which a trantula must eat all the bugs and then exit.

<img width="202" alt="Screen Shot 2022-09-27 at 1 07 21 PM" src="https://user-images.githubusercontent.com/68693691/192509889-f9ad72f3-61fa-49af-a9cb-4c8b54ffca91.png">

## Game attributes:
The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.
* The ```W, A, S, and D``` or the arrow keys are used to move the main character.
* The player is able to move in these 4 directions: up, down, left, right.
* The player cannot move into walls.
* At every move, the current number of movements is displayed in the shell as well as on the window.
* The game has a top down, 2D view.
* ``` ESC ``` exits the game.
* ```R``` resets the game to the starting position. 

### The assets:
The Player:

![AnyConv com__0](https://user-images.githubusercontent.com/68693691/192497974-c3c7b530-e26c-4aa4-87f9-d6b26133ca09.png)

The Collectibles:

![AnyConv com__bug1](https://user-images.githubusercontent.com/68693691/192498200-dc73601a-b02d-48ec-bcab-21ac48172b6f.png)
![AnyConv com__bug2](https://user-images.githubusercontent.com/68693691/192498207-4a7df3b7-00b2-4749-bd23-7573dcd7d1d1.png)
![AnyConv com__bug3](https://user-images.githubusercontent.com/68693691/192498219-7fd790c2-0066-4019-8d54-46751cb1830a.png)

The Exit:

![AnyConv com__hovel](https://user-images.githubusercontent.com/68693691/192498259-d8ef3271-c8bf-4f74-80c2-e5a2c6951305.png)

The Enemy:

![AnyConv com__0(1)](https://user-images.githubusercontent.com/68693691/192498300-c878091c-91c5-481a-980e-6766dc81e90a.png)

## How it works:
The graphics are handled by a library called ```minilibx (MLX)```.

### 1. Parsing the map:
The program takes 1 argument; a map.  The parser makes sure the file has the correct ```.ber``` filetype.  It then uses **get_next_line** to read through the file, each line is then parsed to determine the location of the walls (```1```), collectables (```C```), the players starting position (```P```), the exit (```E```), and navicable tiles (```0```).

**For example:**
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

The parser returns an error if the map:
* doesn't include an exit, collectible, or the players starting position.
* is not rectangula.
* is not enclosed by walls.

### 2. Setting up the game:
The program then takes the information obtained by the parser, initializes all the assets in the correct location and loops through each image in order to correctly place all the asset pixels to an image which is then pushed to the window, through the use of ```MLX``` functions.  Furthermore this stage also assigns number of enemys, which is done through a combination of a random function and the number of empty tiles in the game, as well as their starting positions.

### 3. Waiting for action:
As the ```MLX``` library initiates an infinite loop, the game essentially waits for the player to perform one of the actions.  The enemys moves independently from the player, and an algorithm determines the direction they move in.  If the player presses ```W, A, S, and D``` or the arrow keys, the program first checks if the move is possible, and if the player is on a collectible or the exit.  The program then stores this information.  A seperate loop constantly checks if a move has been made and then alters the location on the image pushed to the window. If the player has consumed all the collectibles and is on the exit the game goes in to ```end_game``` mode. Else, if the player gets eaten (ie touched) by an enemy the game goes into ```game_over``` mode.

## Gameplay:
![ezgif com-gif-maker(1)](https://user-images.githubusercontent.com/68693691/192513482-ae388fc5-9532-4c3e-a185-3643cd27f225.gif)
![ezgif com-gif-maker](https://user-images.githubusercontent.com/68693691/192511286-914c9f52-b897-461a-82b8-ae97404f00fb.gif)


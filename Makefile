GCC = g++ -g

main: main.o Point2d.o Vector2d.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Model.o GameCommand.o View.o Trainer.o 
	$(GCC) main.o Point2d.o Vector2d.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Model.o GameCommand.o View.o Trainer.o -o main

main.o: main.cpp
	$(GCC) -c main.cpp

Point2d.o: Point2d.cpp
	$(GCC) -c Point2d.cpp

Vector2d.o: Vector2d.cpp
	$(GCC) -c Vector2d.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp

PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp

PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

Trainer.o: Trainer.cpp
	$(GCC) -c Trainer.cpp
	
clean:
	rm main.o Point2d.o Vector2d.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Model.o GameCommand.o View.o Trainer.o main
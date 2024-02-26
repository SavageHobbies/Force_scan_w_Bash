using System;
using System.IO;
using System.Collections.Generic;

// Base character class
class Character {

  public string Name { get; set; }
  public int Level { get; set; } 
  public int HP { get; set; }
  public int Attack { get; set; }

  public Character(string name) {
    this.Name = name;
    this.Level = 1;
    this.HP = 100;
    this.Attack = 10;
  }

  public void LevelUp() {
    Level++;
    HP += 20;  
    Attack += 5;
  }
}

// Character subclasses  
class Barbarian : Character {

  public Barbarian(string name): base(name) {

  } 

  public void BerserkerRage() {
    Attack *= 2;
  }

}

class Rogue : Character {

  // Class definition
}

class Mage : Character {
  
  // Class definition 
}


class Game {

  // Game state and logic

  List<Character> characters = new List<Character>();

  void ShowMainMenu() {
    // Menu contents
  }

  void ShowNewGameMenu() {

    string name = GetInput("Enter your name");
    int choice = GetMenuChoice(new string[] {"Barbarian","Rogue","Mage"});
    
    switch(choice) {
      case 0: characters.Add(new Barbarian(name)); break;
      case 1: characters.Add(new Rogue(name)); break;
      case 2: characters.Add(new Mage(name)); break;
    }

    Console.WriteLine("Created character {0}!", characters[0].Name);

  }
  
  void StartNewGame() {
    // Game logic
  }
  
  void SaveGame(string saveFile) {
    // Serialize data
  }

  void LoadGame(string saveFile) {
    // Deserialize data
  }

 // Other methods  

}
// Current problem : i need to press multiple times on a key (1, 2 or ESC). With only ESC as choice
// it was ok but now, maybe i should put do while of EndProgram around all of Main?

//For problem above : Apparently if i remove the keypress checks for 1 and 2, ESC works immediately. 
//Maybe put the choices of 1 and 2 inside the do while? But then won't i lose the possibility
//to reuse the EndProgram? What if the Console wasn't built for such a mix of events?

//Text using CenterText can't be too long or it will make an error by making a negative 
//length for the string of text. Use it only for the main menus, but try to only use
//Write and Writeline in the game itself

//I still haven't managed to figure out how to set a value for the class of the hero after 
//he made a new character

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Input;

namespace Dark_King
{
    class Program
    {

        //Needed import of DLLs to be able to maximize screen on launch
        [DllImport("kernel32.dll", ExactSpelling = true)]

        private static extern IntPtr GetConsoleWindow();
        private static IntPtr ThisConsole = GetConsoleWindow();

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]

        private static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
        private const int HIDE = 0;
        private const int MAXIMIZE = 3;
        private const int MINIMIZE = 6;
        private const int RESTORE = 9;

        //string classe = SelectClass(ref classValue);

        //Variables for character

        static void Main(string[] args)
        {
            Program.MainMenu();
        }

        //Main Menu
        public static void MainMenu()
        {
            //Maximising window to see all - see if needed when menu page done
            ShowWindow(ThisConsole, MAXIMIZE);

            //Setting Foreground colors for Menus
            Console.ForegroundColor = ConsoleColor.White;
            Console.Clear();

            //Logo
            CenterText("          .                                                      .         ");
            CenterText("        .n                   .                 .                  n.       ");
            CenterText("  .   .dP                  dP                   9b                 9b.    .");
            CenterText(" 4    qXb         .       dX                     Xb       .        dXp     ");
            CenterText("t                                                                          ");
            CenterText("dX.    9Xb      .dXb    __                         __    dXb.              ");
            CenterText("dXP     .Xb                                                                ");
            CenterText("9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._           ");
            CenterText("_.dXXP                                                                     ");
            CenterText("                                                                           ");
            CenterText("9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP");
            CenterText("  `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'");
            CenterText("    `9XXXXXXXXXXXP' `9XX'          `98v8P'          `XXP' `9XXXXXXXXXXXP'  ");
            CenterText("        ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~      ");
            CenterText("                        )b.  .dbo.dP'`v'`9b.odb.  .dX(                     ");
            CenterText("                      ,dXXXXXXXXXXXb     dXXXXXXXXXXXb.                    ");
            CenterText("                     dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb                   ");
            CenterText("                    dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb                  ");
            CenterText("                    9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP                  ");
            CenterText("                     `'      9XXXXXX(   )XXXXXXP      `'                   ");
            CenterText("                              XXXX X.`v'.X XXXX                            ");
            CenterText("                              XP^X'`b   d'`X^XX                            ");
            CenterText("                              X. 9  `   '  P )X                            ");
            CenterText("                              `b  `       '  d'                            ");
            CenterText("                               `             '                             ");


            //Ascii title
            Console.ForegroundColor = ConsoleColor.Red;
            CenterText(@"________                __      ____  __.__                ");
            CenterText(@"\______ \ _____ _______|  | __ |    |/ _|__| ____    ____  ");
            CenterText(@" |    |  \\__  \\_  __ \  |/ / |      < |  |/    \  / ___\ ");
            CenterText(@" |    `   \/ __ \|  | \/    <  |    |  \|  |   |  \/ /_/  >");
            CenterText(@"/_______  (____  /__|  |__|_ \ |____|__ \__|___|  /\___  / ");
            CenterText(@"        \/     \/           \/         \/       \//_____/  ");


            //Subtitle
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine(" ");
            CenterText("A Sean Sandoval game");
            Console.WriteLine(" ");
            Console.WriteLine(" ");


            //Menu for when press button
            Console.ForegroundColor = ConsoleColor.White;
            CenterText("NEW GAME");
            CenterText("(Press 1)");
            Console.WriteLine(" ");
            CenterText("LOAD GAME");
            CenterText("(Press 2)");
            Console.WriteLine(" ");
            CenterText("EXIT");
            CenterText("(Press Escape)");
            Console.WriteLine(" ");


            if (Console.ReadKey(true).Key == ConsoleKey.D1)
            { Program.NewGame(); }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad1)
            { Program.NewGame(); }
            else if (Console.ReadKey(true).Key == ConsoleKey.D2)
            { Program.LoadGame(); }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad2)
            { Program.LoadGame(); }

            Program.EndProgram();

        }

        public static string NewGame()
        {
            Console.Clear();

            string classeValue = "Agent";

            CenterText("NEW GAME");
            CenterText(" ");
            CenterText("CREATE YOUR CHARACTER");
            CenterText(" ");
            //I need to add option to name it
            CenterText("1. Brute force and boundless destruction is your playstyle.");
            CenterText("Become a barbarian. His special ability at level 1 : \"Berserker Rage\".");
            CenterText("Activate it to destroy your enemies faster!");
            CenterText(" ");
            CenterText("2. Quick reflexes and a knife in the back suits you.");
            CenterText("Become a rogue. His special ability at level 1 : \"Assassination\".");
            CenterText("Activate it to kill enemies in one shot!");
            CenterText(" ");
            CenterText("3. Wise decisions and varied spells are more to your liking.");
            CenterText("Become a mage.His special ability at level 1 : \"Healing spell\".");
            CenterText("Activate it to heal yourself without the need to use potions!");

            if (Console.ReadKey(true).Key == ConsoleKey.D1)
            { classeValue = "Barbarian";
                Program.StartStoryValley(classeValue);
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad1)
            {
                classeValue = "Barbarian";
                Program.StartStoryValley(classeValue);
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.D2)
            {
                classeValue = "Rogue";
                Program.StartStoryValley(classeValue);
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad2)
            {
                classeValue = "Rogue";
                Program.StartStoryValley(classeValue);
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.D3)
            {
                classeValue = "Mage";
                Program.StartStoryValley(classeValue);
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad3)
            {
                classeValue = "Mage";
                Program.StartStoryValley(classeValue);
            }

            Program.EndProgram();
            return classeValue;
        }

        //public static string SelectClass(ref string classeValue)
        //{
        //    if classeValue = "Barbarian"
        //
        //return classe;
        //}

        public static void StartStoryValley(string classe)
        {
            Console.Clear();

            CenterText(" ");
            CenterText("Your " + classe + " is ready!");
            Program.EndProgram();
        }


        public static void LoadGame()
        {
            Console.Clear();

            CenterText("LOAD GAME");
            CenterText(" ");
            CenterText("1. Load the following save :");
            CenterText(" ");
            CenterText("2. Return to Main Menu");

            if (Console.ReadKey(true).Key == ConsoleKey.D1)
            {
                CenterText("This functionality is not yet available.");
                CenterText("Press any key and you will be redirected to the Main Menu.");
              Console.ReadLine();
              Program.MainMenu();
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad1)
            {
                CenterText("This functionality is not yet available.");
                CenterText("Press any key and you will be redirected to the Main Menu.");
                Console.ReadLine();
                Program.MainMenu();
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.D2)
            { Program.MainMenu(); }
            else if (Console.ReadKey(true).Key == ConsoleKey.NumPad2)
            { Program.MainMenu(); }

            Program.EndProgram();
        }

        public static void CenterText(string text)
        {

            Console.Write(new string(' ', (Console.WindowWidth - text.Length) / 2));
            Console.WriteLine(text);
        }

        public static void EndProgram()
        {
            //Makes the machine do anything before it closes with Escape
            do
            {
                while (!Console.KeyAvailable)
                {

                }
            } while (Console.ReadKey(true).Key != ConsoleKey.Escape);
        }



        }

    }


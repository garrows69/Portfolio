using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;

namespace DiscordBotTest.Misc
{
    public class RandomWord
    {

        private ArrayList array = new ArrayList();
        private Random random = new Random();

        public RandomWord()
        {
            array.Add("Asshole");
            array.Add("Dyke");
            array.Add("Fag");
            array.Add("Shit");
            array.Add("Damn");
            array.Add("Fuck");
            array.Add("Jerkoff");
            array.Add("Ass");
            array.Add("Prick");
            array.Add("Damn");
            array.Add("Whore");
            array.Add("Twat");
            array.Add("Piece of Shit");
        }

        public string genWord()
        {
            string result = (array[random.Next(0, array.Count)] + " you, you " + array[random.Next(0, array.Count)] + ". You really think I am going to play this game with you? Who do you think i am! You're little " + array[random.Next(0, array.Count)] + "! " + array[random.Next(0, array.Count)] + " man!");
            return result;
        }

    }
}

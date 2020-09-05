using System;
using System.Collections.Generic;
using System.Text;

namespace DiscordBotTest.DatatStructs
{
    public class BotConfig
    {
        public string DiscordToken { get; set; }
        public string DefaultPrefix { get; set; }
        public string GameStatus { get; set; }
        public List<ulong> BlacklistedChannels { get; set; }
    }
}

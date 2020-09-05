using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using Discord;
using Discord.Commands;
using Discord.WebSocket;
using DiscordBotTest.Services;
using Microsoft.Extensions.DependencyInjection;
using Victoria;

namespace DiscordBotTest
{
    class DiscordBotTest
    {
        private static Task Main()
            => new DiscordService().InitializeAsync();
    }
}
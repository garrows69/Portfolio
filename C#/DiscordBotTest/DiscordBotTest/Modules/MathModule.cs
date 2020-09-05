using Discord.Commands;
using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace DiscordBotTest.Modules
{
    public class MathModule : ModuleBase<SocketCommandContext>
    {
        [Command("square")]
        [Summary("Squares a number")]
        public async Task SquareAsync(
            [Summary("The number to square.")] int num)
        {
            await Context.Channel.SendMessageAsync($"{num}^2 = {Math.Pow(num, 2)}");
        }
    }
}

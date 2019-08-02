<img src="https://cdn.rawgit.com/emilwallner/Corewar/master/images/corewarlogo.svg" width="100%">

---

**Final 21 school project.**

The idea of the project is to rewrite the famous game **Core Wars**.

All terms and descriptions of the game you can find on Wiki (https://en.wikipedia.org/wiki/Core_War).

In simple words, the project consists of the following parts:

- **The assembly**, a guy, which translates the assembler code of players into bytecode.
- **The game board**, or the virtual machine. The memory of our virtual computer. It’s represented in a 64 X 64 grid of bytes.
- **The players**, small programs. The white parts have blank memory.

## Okay, here we go

So, first tou need to "prepare" the player for your(ours) Virtual Machine.

You can find all the players in **champs** folder.

For example, here is a player called [Batman.s](champs/Batman.s).

![alt text](https://github.com/ksnow-be/Corewar/blob/master/imgs/Batman.png)

To translate this thing into byte code, we need to split the champion assembly code into tokens.

For exactly first 2 strings code of this player would be:

| Lexem | Value |
| --- | --- |
| loop: | LABEL |
| sti | INSTRUCTION |
| r1 | REGISTER |
| , | SEPARATOR |
| %:live | DIRECT_LABEL |
| , | SEPARATOR |
| %1 | DIRECT |

So after you split the player’s code into tokens, you write the size of the executable code and the code itself into a binary file with **".cor"** extension.

![alt text](https://github.com/ksnow-be/Corewar/blob/master/imgs/ASM.png)

Done. Your player is ready to fight.

## The game

So, after your players are ready, tou can start the War.

```
./corewar <name>.cor <name2>.cor
```


Players run through vm memory and bite each other's memory from the way they were programmed.

The VM field looks like this:

![alt text](https://github.com/ksnow-be/Corewar/blob/master/imgs/field.png)

The only player showing signs of life is considered the winner.

![alt text](https://github.com/ksnow-be/Corewar/blob/master/imgs/battle.png)

**In our team i was responsible for splitting on tokens and bytecode translation, so honestly i have no clue how VM works. Sorry.**

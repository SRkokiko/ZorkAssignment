# Lost and Found

A text-based horror game in the tradition of Zork. You wake on a forest, starving and cold, and find yourself drawn toward a vast mansion that should not exist. Navigate its impossible rooms, uncover its secrets, and decide how your story ends.

The game has **two minor endings** and a **true ending** — see if you can reach the true one.

---

## Authors

- **Pau Bermudez Valle** ([@SRkokiko](https://github.com/SRkokiko))

---

## Repository

[https://github.com/SRkokiko/ZorkAssignment](https://github.com/SRkokiko/ZorkAssignment)

---

## License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

## Download

A prebuilt Windows x64 executable is available on the [Releases page](https://github.com/SRkokiko/ZorkAssignment/releases). Download and run `Zork.exe` directly — no build step required.

---

## How to Build

Built with **Visual Studio 2019 Community** targeting Windows x64.

1. Open `Zork.sln` in Visual Studio 2019.
2. Set the configuration to **Release | x64**.
3. **Build → Build Solution** (`Ctrl+Shift+B`).
4. The executable will be at `Zork\x64\Release\Zork.exe`.

The project compiles cleanly at **Warning Level 3** (`/W3`) with no warnings.

---

## How to Play

The game is played entirely through text commands.

### Commands

| Command | Description |
|---------|-------------|
| `go <target>` | Move through an entrance |
| `use <target>` | Use an item or entrance |
| `talk <target>` | Start a conversation |
| `pick <target>` | Pick up an item |
| `take <target> from <container>` | Take an item out of a container |
| `drop <target>` | Drop an item from your inventory |
| `put <target> in <container>` | Place an inventory item into a container |
| `inventory` / `i` | List carried items |
| `look` / `l` | Re-describe the current room |
| `help` / `h` | Show available commands |
| `quit` / `exit` | Quit the game |

### Tips

- **UPPERCASE BOLD** words in descriptions are interactive elements — you can use them as targets for commands.
- Commands are case-insensitive.
- If the game doesn't understand you, try rephrasing or typing `help`.

---

## Walkthrough

> **Spoilers below.** Only read this if you are stuck.

<details>
<summary>Ending 1 — Freedom</summary>

From the exterior (starting room), type:

```
go forest
```
</details>

<details>
<summary>Ending 2 — Sinner</summary>

Follow the True Ending steps below, but add the **MEAT** to the **POT** before eating.

</details>

<details>
<summary>True Ending — Found</summary>

### Step 1 — Enter the Mansion

You start at the exterior of the mansion. The front **DOOR** is locked.

```
take rusty key
use rusty key
go door
```

The **RUSTY KEY** unlocks the door. You step inside the mansion's corridor.

---

### Step 2 — Reach the Hall

```
go white door
```

The **WHITE DOOR** on your right leads to the hall.

---

### Step 3 — Talk to the Lady

There is a **LADY** seated in the room. Talk to her and follow this dialogue path:

```
talk lady
```

1. *"Hello?"*
2. *"What should I do?"*
3. *"Eat."*
4. *"Thanks?"*

After this exchange, a **YELLOW DOOR** will appear in the hall.

---

### Step 4 — Reach the Kitchen

```
go yellow door
```

You reach the kitchen, filled with ingredients.

---

### Step 5 — Prepare the Stew (without Meat)

Pick up and place the correct ingredients into the **POT**. Do not add the **MEAT**, as the **LADY** told you not to.

```
take water
take carrot
take potato
take mushroom
take pot
put water into pot
put carrot into pot
put potato into pot
put mushroom into pot
```

Then eat (while still located on the kitchen):

```
use pot
```

The mansion shifts and the **HOLE** in the corridor is finally open.

---

### Step 6 — Enter the Hole

Navigate back to the corridor:

```
go door
go white door
```

Once in the corridor:

```
go hole
```

You step into the darkness.

</details>


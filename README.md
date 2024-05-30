# BFF

A terminal-based curses filebrowser. Unix only. WIP.

## Building

Ensure `curses` is installed, along with `cmake` and `make`. Run `make` to
compile. `make clean` cleans build files.

## Mappings

| Key | Description |
|-----|-------------|
| `:` | Enter command mode |
| `h` | Traverse to the parent |
| `j` | Move selection down |
| `k` | Move selection up |
| `l` | Traverse into the folder |

## Commands

| CMD | Description |
|-----|-------------|
| `:q` | Exit the program. |

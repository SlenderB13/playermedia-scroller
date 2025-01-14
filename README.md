# Playermedia Scroller

Display the media playing in Polybar.

https://github.com/user-attachments/assets/f44b323a-a4e4-462b-a553-efd82592c29d

## Dependencies
* [playerctl](https://github.com/altdesktop/playerctl)

This program gathers information from the [playerctl](https://github.com/altdesktop/playerctl) library, so make sure you have it.

## How to install

### From source
```bash
git clone https://github.com/SlenderB13/playermedia-scroller/
cd playermedia-scroller
make
```

### From package managers
(Not available yet)

## How to run it

### Terminal

You can run it in your terminal by calling the binary.
```bash
./playermedia-scroller
```

### Polybar

This program is made to integrate with [Polybar](https://github.com/polybar/polybar), so to use it you must:

1. `cd` into `playermedia-scroll` folder and make both the scripts `mediaplayer-buttons` and `mediaplayer-source` callable with `chmod +x ./mediaplayer-buttons.sh ./mediaplayer-source.sh`.

2. Add the modules commands to your `/.config/polybar/config.ini`
> Don't forget to point the path to the files inside the folder you just donwloaded.

```ini
[module/mediaplayer]
type = custom/script
exec = /path/to/playermedia-scroller
#interval = 0.5
interval = 1
tail = true

[module/mediaplayer-source]
type = custom/script
exec = /path/to/mediaplayer-source.sh
interval = 1

[module/mediaplayer-buttons]
type = custom/script
exec = /path/to/mediaplayer-buttons.sh
interval = 0.8
```

3. Add the modules to the bar

```ini
modules-center = mediaplayer-source mediaplayer mediaplayer-buttons
```
> I use it at the center, but you can choose where to put it.

4. You can choose which modules to add to the bar. Maybe you want only the player but not the buttons.

___

## Roadmap

This project is in its first steps, so you can help to make it better.

### To-do
- [x] Add support to icons, like `spotify` or `chrome`.
- [ ] Maybe stop truncating huge titles??

### To-fix
- [x] Random CPU spikes.
- [x] Width increases when title is too big, causing the buttons to move.(fixed by truncating)
- [x] Weird characters rendered when the title is to big. (fixed by truncating)

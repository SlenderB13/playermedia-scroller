## Dependencies
This program gathers information from the [playerctl](https://github.com/altdesktop/playerctl) library, so you must have it.

## How to install

```bash
git clone https://github.com/SlenderB13/playermedia-scroller/
cd playermedia-scroller
make
```

## How to run it

### Terminal

You can run it in your terminal by calling the binary.
```bash
./playermedia-scroller
```

### Polybar

This program is made to integrate with [Polybar](https://github.com/polybar/polybar), so to use it you must:

1. Add the modules commands to your `/.config/polybar/config.ini`

```ini
[module/mediaplayer]
type = custom/script
exec = /home/$HOME/.config/polybar/playermedia-scroller
#interval = 0.5
interval = 1
tail = true

[module/mediaplayer-source]
type = custom/script
exec = echo "($(playerctl metadata --format '{{playerName}}'))"
interval = 1

[module/mediaplayer-buttons]
type = custom/script
exec = /home/$HOME/.config/polybar/mediaplayer-buttons.sh
interval = 0.8
```

2. Add the modules to the bar

```ini
modules-center = mediaplayer-source mediaplayer mediaplayer-buttons
```
> I use it at the center, but you can choose where to put it.

3. You can choose which modules to add to the bar. Maybe you want only the player but not the buttons.

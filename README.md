# Playermedia Scroller

Display the media playing in Polybar.

![Demo](./demo/player-scroller.mkv)

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

1. Create a `/.config/polybar/mediaplayer-buttons.sh` file and paste the script for the `previous`, `play/pause` and `next` buttons.

```bash
#!/bin/bash

playerctlstatus=$(playerctl status 2> /dev/null)

if [[ $playerctlstatus ==  "" ]]; then
    echo ""
elif [[ $playerctlstatus =~ "Playing" ]]; then
	echo "%{A1:playerctl previous:}◀%{A} %{A1:playerctl play-pause:}❚❚%{A} %{A1:playerctl next:}▶%{A}"
else
	echo "%{A1:playerctl previous:}◀%{A} %{A1:playerctl play-pause:}▷%{A} %{A1:playerctl next:}▶%{A}"
fi
```
> [!TIP]
> You can also play and pause by clicking in the media info, not only via buttons.

2. Add the modules commands to your `/.config/polybar/config.ini`
> Don't forget to edit the path to your `playermedia-controller` binary.

```ini
[module/mediaplayer]
type = custom/script
exec = path/to/playermedia-scroller
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

3. Add the modules to the bar

```ini
modules-center = mediaplayer-source mediaplayer mediaplayer-buttons
```
> I use it at the center, but you can choose where to put it.

4. You can choose which modules to add to the bar. Maybe you want only the player but not the buttons.

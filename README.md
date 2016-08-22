# Ft_select
This programm is a 42 school project.

To introduce C termcap library and some signal handling.

He take in parameter a list of arguments:

```./ft_select arg1 arg2 arg3 arg4```

or

```./ft_select ./* | rm``` 

or

```cp `./ft_select ./*` ../otherfolder``` 

And provide a simple terminal based interface allowing you to select or delete the arguments. And return the list of the selected arguments.

## Installation
*Work on UNIX system only*
```
git clone git@gitlab.com:avallete/ft_select.git
cd ft_select
git submodule update --init --recursive
make
```

### Requirements
You can also need to run ```sudo apt-get install libncurses-dev libc-dev gcc``` 


## Usage
Commands:

    "D": Delete all selected elements from the list.

	"Delete/Backspace": Delete the current element.

	"Escape": Quit the programm without returning any element.

	"Espace": Toggle selection on the current element and go to the next argument.

	"Arrows(Up/Left/Right/Down)": Move between elements/pages.

	"Enter": Return list of selected elements to the shell with space separation.

## Demo
![Imgur](http://i.imgur.com/Lzlsf9W.gifv "Demo gif")

<sub><sup>(Gif created with https://github.com/icholy/ttygif)</sub></sup>

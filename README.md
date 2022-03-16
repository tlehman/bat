# bat (battery status command)

I installed Arch Linux on my Thinkpad T460S and wanted to find the 
battery level without a GUI. So I found the file 
`/sys/class/power_supply/BAT0/capacity`, and my laptop has a second 
battery, so there's a `BAT1` file for that one too.

I wrote [bat.sh](bat.sh) to display this status:

```
Battery #1 (98)%: [##################################################################################################--]
Battery #2 (100)%: [####################################################################################################]
```

But I also found that it took about 25ms to run, which is too much, so 
I re-wrote it in C to create [bat.c](bat.c). That runs in about 15ms.

```
Battery #1 (98)%: [##################################################################################################--]
Battery #2 (100)%: [####################################################################################################]
```

# How to compile

```
make
```

literally just type `make`


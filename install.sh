MESSAGE=\""A computer is like air conditioning - it becomes useless when you open Windows.     -Linus Torvalds\""
echo "~/Epita-XFCE4-Config/fetch-master-6000/./fm6000 -l 80 -s $MESSAGE" >> ~/.bashrc
cp terminalrc ~/.config/xfce4/terminal/terminalrc
feh --bg-scale bg.jpg
cp xfce4-desktop.xml ~/.config/xfce4/xfconf/xfce-perchannel-xml/xfce4-desktop.xml

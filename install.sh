MESSAGE=\""A computer is like air conditioning - it becomes useless when you open Windows.     -Linus Torvalds\""
git clone https://github.com/anhsirk0/fetch-master-6000.git
cd fetch-master-6000
./install.sh
cd ~/Epita-XFCE4-Config
echo "~/Epita-XFCE4-Config/fetch-master-6000/./fm6000 -l 80 -s $MESSAGE" >> ~/.bashrc
echo "xrandr -s 1920x1080" >> ~/.bashrc
echo "feh --bg-scale ~/Epita-XFCE4-Config/bg.jpg" >> .bashrc
cp terminalrc ~/.config/xfce4/terminal/terminalrc
xrandr -s 1920x1080
feh --bg-scale bg.jpg
cp xfce4-desktop.xml ~/.config/xfce4/xfconf/xfce-perchannel-xml/xfce4-desktop.xml

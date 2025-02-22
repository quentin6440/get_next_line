admin useful commands

ssh config file :
/etc/ssh/sshd_config

sudo systemctl status ssh
sudo grep Port /etc/ssh/sshd_config
sudo systemctl restart ssh

uncomplicated firewall
sudo apt install ufw
sudo ufw enable
sudo ufw allow 4242
sudo ufw status numbered
sudo ufw delete [number]

connect to the guest from the host
ssh username@127.0.0.1 -p 4242
also works with localhost

dont forget about the port forwarding in VB settings(4243 -> 4242)


sudo
usermod -aG [sudo] [your_username] //add a user to a new group

getent group [sudo] //

pw policy
sudo apt-get install libpam-pwquality
PAM config file : sudo vim /etc/pam.d/common-password
password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
//uppercase, lower, digit, difok(nb char differ from last pw)
sudo vim /etc/login.defs //default settings
#PASS_MAX_DAYS 30 , PASS_MIN_DAYS 2 , PASS_WARN_AGE 7
chage -M <num max>, chage -m <num>, chage -W <num> // mod settings
chage -l username //current pw info

sudo groupadd user42
getent group <group_name>
cd /etc/passwd // file containing users
sudo delgroup <group_name>
sudo usermod -aG user42 username
groups //display groups user belongs to

cd /var/log //dir for log files about system events, services, processes
sudo vim /etc/sudoers or sudo visudo
Defaults requiretty


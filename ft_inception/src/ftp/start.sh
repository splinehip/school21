mkdir -p /home/tutsi
chown -R tutsi:tutsi /home/tutsi
echo tutsi | tee -a /etc/vsftpd.userlist
vsftpd /etc/vsftpd.conf

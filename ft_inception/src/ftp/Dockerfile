FROM debian:buster

RUN apt-get  update
RUN apt-get upgrade -y
RUN apt-get install vsftpd  -y
RUN apt-get install  openssl -y
RUN apt-get install  jq -y
RUN apt-get install  curl -y
RUN apt-get install openssh-server -y
RUN echo -e "MA\nKH\nKHOURIBGA\n1337Ltd\nOCP\nOCP SA\tutsi@mail.ru\n" | openssl req \
			-x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.pem -out \
			/etc/ssl/private/vsftpd.pem
RUN cd var/run/
RUN mkdir -p  var/run/vsftpd/empty
RUN adduser 'tutsi'
RUN echo "tutsi:root" | chpasswd
RUN ssh-keygen -A
COPY vsftpd.conf etc/
EXPOSE 21
COPY start.sh /
ENTRYPOINT ["sh", "start.sh"]

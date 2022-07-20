FROM debian:buster

RUN apt-get update -y

RUN apt-get upgrade -y 

EXPOSE 9000

RUN apt install -y vim
RUN apt install -y unzip
RUN apt install -y wget
RUN apt install -y php-fpm php-mysql
RUN apt upgrade -y
RUN mkdir -p /var/www/html
COPY ./wp-config.php /
RUN service php7.3-fpm start
RUN service php7.3-fpm stop
RUN chmod 777 /var/www/html/
COPY ./www.conf /etc/php/7.3/fpm/pool.d/
COPY ./php-fpm.conf /etc/php/7.3/fpm/
COPY ./start.sh ./start.sh
COPY ./redis-cache.tar.gz .
RUN tar -xzvf ./redis-cache.tar.gz redis-cache
#RUN mv /redis-cache /var/www/html/wp-content/plugins/
ENTRYPOINT ["bash","start.sh"]


 wget http://wordpress.org/latest.tar.gz &&\
    tar -xzvf latest.tar.gz &&\
    rm latest.tar.gz && cp -rf /wordpress/* /var/www/html && cp -rf  /wp-config.php /var/www/html

chown www-data:www-data -R /var/www/html/*
mv /redis-cache /var/www/html/wp-content/plugins/
php-fpm7.3 --nodaemonize

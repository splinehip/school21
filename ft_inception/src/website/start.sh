cp -rf index.html  /var/www/html
cp -rf style.html /var/www/html

chown -R www-data:www-data /var/www/html/*
chmod 755 /var/www/html/*


php -S 0.0.0.0:8008


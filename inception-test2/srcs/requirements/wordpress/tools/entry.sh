sleep 10

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir -p /run/php

cd /var/www

wp core install --allow-root --path=/var/www \
								--url=siwolee.42.fr \
								--title=Inception \
								--admin_user=$WP_ADMIN \
								--admin_password=$WP_ADMIN_PW \
								--admin_email=siwolee@student.42seoul.kr \
								--skip-email

wp user create $WP_USER user42@student.42seoul.kr \
							--allow-root --path=/var/www \
							--role=author \
							--user_pass=$WP_USER_PW

sleep 5
exec  php-fpm7.4 -F
